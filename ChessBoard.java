package chess;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;

import javax.swing.*;
import javax.swing.border.*;
import java.util.Iterator;
import java.util.Set;
import java.util.HashSet;
//======================================================Don't modify below===============================================================//
enum PieceType {king, queen, bishop, knight, rook, pawn, none}
enum PlayerColor {black, white, none}

public class ChessBoard {
	private final JPanel gui = new JPanel(new BorderLayout(3, 3));
	private JPanel chessBoard;
	private JButton[][] chessBoardSquares = new JButton[8][8];
	private Piece[][] chessBoardStatus = new Piece[8][8];
	private ImageIcon[] pieceImage_b = new ImageIcon[7];
	private ImageIcon[] pieceImage_w = new ImageIcon[7];
	private JLabel message = new JLabel("Enter Reset to Start");

	ChessBoard(){
		initPieceImages();
		initBoardStatus();
		initializeGui();
	}

	public final void initBoardStatus(){
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++) chessBoardStatus[j][i] = new Piece();
		}
	}

	public final void initPieceImages(){
		pieceImage_b[0] = new ImageIcon(new ImageIcon("./img/king_b.png").getImage().getScaledInstance(64, 64, java.awt.Image.SCALE_SMOOTH));
		pieceImage_b[1] = new ImageIcon(new ImageIcon("./img/queen_b.png").getImage().getScaledInstance(64, 64, java.awt.Image.SCALE_SMOOTH));
		pieceImage_b[2] = new ImageIcon(new ImageIcon("./img/bishop_b.png").getImage().getScaledInstance(64, 64, java.awt.Image.SCALE_SMOOTH));
		pieceImage_b[3] = new ImageIcon(new ImageIcon("./img/knight_b.png").getImage().getScaledInstance(64, 64, java.awt.Image.SCALE_SMOOTH));
		pieceImage_b[4] = new ImageIcon(new ImageIcon("./img/rook_b.png").getImage().getScaledInstance(64, 64, java.awt.Image.SCALE_SMOOTH));
		pieceImage_b[5] = new ImageIcon(new ImageIcon("./img/pawn_b.png").getImage().getScaledInstance(64, 64, java.awt.Image.SCALE_SMOOTH));
		pieceImage_b[6] = new ImageIcon(new BufferedImage(64, 64, BufferedImage.TYPE_INT_ARGB));

		pieceImage_w[0] = new ImageIcon(new ImageIcon("./img/king_w.png").getImage().getScaledInstance(64, 64, java.awt.Image.SCALE_SMOOTH));
		pieceImage_w[1] = new ImageIcon(new ImageIcon("./img/queen_w.png").getImage().getScaledInstance(64, 64, java.awt.Image.SCALE_SMOOTH));
		pieceImage_w[2] = new ImageIcon(new ImageIcon("./img/bishop_w.png").getImage().getScaledInstance(64, 64, java.awt.Image.SCALE_SMOOTH));
		pieceImage_w[3] = new ImageIcon(new ImageIcon("./img/knight_w.png").getImage().getScaledInstance(64, 64, java.awt.Image.SCALE_SMOOTH));
		pieceImage_w[4] = new ImageIcon(new ImageIcon("./img/rook_w.png").getImage().getScaledInstance(64, 64, java.awt.Image.SCALE_SMOOTH));
		pieceImage_w[5] = new ImageIcon(new ImageIcon("./img/pawn_w.png").getImage().getScaledInstance(64, 64, java.awt.Image.SCALE_SMOOTH));
		pieceImage_w[6] = new ImageIcon(new BufferedImage(64, 64, BufferedImage.TYPE_INT_ARGB));
	}

	public ImageIcon getImageIcon(Piece piece){
		if(piece.color.equals(PlayerColor.black)){
			if(piece.type.equals(PieceType.king)) return pieceImage_b[0];
			else if(piece.type.equals(PieceType.queen)) return pieceImage_b[1];
			else if(piece.type.equals(PieceType.bishop)) return pieceImage_b[2];
			else if(piece.type.equals(PieceType.knight)) return pieceImage_b[3];
			else if(piece.type.equals(PieceType.rook)) return pieceImage_b[4];
			else if(piece.type.equals(PieceType.pawn)) return pieceImage_b[5];
			else return pieceImage_b[6];
		}
		else if(piece.color.equals(PlayerColor.white)){
			if(piece.type.equals(PieceType.king)) return pieceImage_w[0];
			else if(piece.type.equals(PieceType.queen)) return pieceImage_w[1];
			else if(piece.type.equals(PieceType.bishop)) return pieceImage_w[2];
			else if(piece.type.equals(PieceType.knight)) return pieceImage_w[3];
			else if(piece.type.equals(PieceType.rook)) return pieceImage_w[4];
			else if(piece.type.equals(PieceType.pawn)) return pieceImage_w[5];
			else return pieceImage_w[6];
		}
		else return pieceImage_w[6];
	}

	public final void initializeGui(){
		gui.setBorder(new EmptyBorder(5, 5, 5, 5));
	    JToolBar tools = new JToolBar();
	    tools.setFloatable(false);
	    gui.add(tools, BorderLayout.PAGE_START);
	    JButton startButton = new JButton("Reset");
	    startButton.addActionListener(new ActionListener(){
	    	public void actionPerformed(ActionEvent e){
	    		initiateBoard();
	    	}
	    });

	    tools.add(startButton);
	    tools.addSeparator();
	    tools.add(message);

	    chessBoard = new JPanel(new GridLayout(0, 8));
	    chessBoard.setBorder(new LineBorder(Color.BLACK));
	    gui.add(chessBoard);
	    ImageIcon defaultIcon = new ImageIcon(new BufferedImage(64, 64, BufferedImage.TYPE_INT_ARGB));
	    Insets buttonMargin = new Insets(0,0,0,0);
	    for(int i=0; i<chessBoardSquares.length; i++) {
	        for (int j = 0; j < chessBoardSquares[i].length; j++) {
	        	JButton b = new JButton();
	        	b.addActionListener(new ButtonListener(i, j));
	            b.setMargin(buttonMargin);
	            b.setIcon(defaultIcon);
	            if((j % 2 == 1 && i % 2 == 1)|| (j % 2 == 0 && i % 2 == 0)) b.setBackground(Color.WHITE);
	            else b.setBackground(Color.gray);
	            b.setOpaque(true);
	            b.setBorderPainted(false);
	            chessBoardSquares[j][i] = b;
	        }
	    }

	    for (int i=0; i < 8; i++) {
	        for (int j=0; j < 8; j++) chessBoard.add(chessBoardSquares[j][i]);

	    }
	}

	public final JComponent getGui() {
	    return gui;
	}

	public static void main(String[] args) {
	    Runnable r = new Runnable() {
	        @Override
	        public void run() {
	        	ChessBoard cb = new ChessBoard();
                JFrame f = new JFrame("Chess");
                f.add(cb.getGui());
                f.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
                f.setLocationByPlatform(true);
                f.setResizable(false);
                f.pack();
                f.setMinimumSize(f.getSize());
                f.setVisible(true);
            }
        };
        SwingUtilities.invokeLater(r);
	}

//================================Utilize these functions========================================//

	class Piece{
		PlayerColor color;
		PieceType type;


		Piece(){
			color = PlayerColor.none;
			type = PieceType.none;
		}
		Piece(PlayerColor color, PieceType type){
			this.color = color;
			this.type = type;
		}
	}

	public void setIcon(int x, int y, Piece piece){
		chessBoardSquares[y][x].setIcon(getImageIcon(piece));
		chessBoardStatus[y][x] = piece;
	}

	public Piece getIcon(int x, int y){
		return chessBoardStatus[y][x];
	}

	public void markPosition(int x, int y){
		chessBoardSquares[y][x].setBackground(Color.pink);
	}

	public void unmarkPosition(int x, int y){
		if((y % 2 == 1 && x % 2 == 1)|| (y % 2 == 0 && x % 2 == 0)) chessBoardSquares[y][x].setBackground(Color.WHITE);
		else chessBoardSquares[y][x].setBackground(Color.gray);
	}

	public void setStatus(String inpt){
		message.setText(inpt);
	}

	public void initiateBoard(){
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++) setIcon(i, j, new Piece());
		}
		setIcon(0, 0, new Piece(PlayerColor.black, PieceType.rook));
		setIcon(0, 1, new Piece(PlayerColor.black, PieceType.knight));
		setIcon(0, 2, new Piece(PlayerColor.black, PieceType.bishop));
		setIcon(0, 3, new Piece(PlayerColor.black, PieceType.queen));
		setIcon(0, 4, new Piece(PlayerColor.black, PieceType.king));
		setIcon(0, 5, new Piece(PlayerColor.black, PieceType.bishop));
		setIcon(0, 6, new Piece(PlayerColor.black, PieceType.knight));
		setIcon(0, 7, new Piece(PlayerColor.black, PieceType.rook));
		for(int i=0;i<8;i++){
			setIcon(1, i, new Piece(PlayerColor.black, PieceType.pawn));
			setIcon(6, i, new Piece(PlayerColor.white, PieceType.pawn));
		}
		setIcon(7, 0, new Piece(PlayerColor.white, PieceType.rook));
		setIcon(7, 1, new Piece(PlayerColor.white, PieceType.knight));
		setIcon(7, 2, new Piece(PlayerColor.white, PieceType.bishop));
		setIcon(7, 3, new Piece(PlayerColor.white, PieceType.queen));
		setIcon(7, 4, new Piece(PlayerColor.white, PieceType.king));
		setIcon(7, 5, new Piece(PlayerColor.white, PieceType.bishop));
		setIcon(7, 6, new Piece(PlayerColor.white, PieceType.knight));
		setIcon(7, 7, new Piece(PlayerColor.white, PieceType.rook));
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++) unmarkPosition(i, j);
		}
		onInitiateBoard();
	}
//======================================================Don't modify above==============================================================//

//======================================================Implement below=================================================================//
	//NOTE I implemented this
	class Tuple<X,Y>{
		public X x;
		public Y y;
		Tuple(X x, Y y){
			this.x=x;
			this.y=y;
		}
	}

	boolean flag=true;
	boolean isFirst=true;
	boolean check_B=false;//B is checked
	boolean checkmate_B=false;//B is chekcmated
	boolean check_W=false;//W is checked
	boolean checkmate_W=false;//W is checkmated
	boolean win_W=false;//king B is dead
	boolean win_B=false;//king W is dead 
	int origin_x, origin_y;
	Set<Tuple<Integer,Integer>> pinkpiece;

	class ButtonListener implements ActionListener{
		int x;
		int y;

		ButtonListener(int x, int y){
			this.x = x;
			this.y = y;
		}
		public void actionPerformed(ActionEvent e) {	// Only modify here
			//System.out.println(x+" "+y);
			//no king, game ends
			Piece[][] origin_board=new Piece[8][8];
			for(int i=0;i<8;i++)
				for(int j=0;j<8;j++)
					origin_board[i][j]=getIcon(i,j);
			Piece w_king=new Piece(PlayerColor.white,PieceType.king);
			Piece b_king=new Piece(PlayerColor.black,PieceType.king);
			if(checkmate_B){
				setStatus("CHEKCMATE: WHITE WIN"); 
			}
			if(checkmate_W){
				setStatus("CHEKCMATE: BLACK WIN");
			}
			if(win_B){
				setStatus("BLACK WIN");
			}
			if(win_W){
				setStatus("WHITE WIN");
			}
			if(!checkmate_B&&!checkmate_W&&!win_B&&!win_W){
				//change
				if(flag){
					//BLACK's TURN
					if(isFirst){
						origin_x=x;
						origin_y=y;
						//1.mark pink pieces
						if(getIcon(x,y).color.equals(PlayerColor.black)){
							pinkpiece=PinkPiece(x,y,null);
							if(pinkpiece.size()>0){
								Iterator<Tuple<Integer, Integer>> itr=pinkpiece.iterator();
								while(itr.hasNext()){
									Tuple<Integer,Integer> pos=itr.next();
									markPosition(pos.x,pos.y);
								}
								isFirst=false;
							}
						}
					}else{
						//2.move into pink piece
						if(isPinkPiece(x,y,pinkpiece)){

							//	update piece
							setIcon(x,y,getIcon(origin_x,origin_y));
							setIcon(origin_x,origin_y,new Piece(PlayerColor.none,PieceType.none));
							//unmark position
							if(pinkpiece.size()>0){
								Iterator<Tuple<Integer,Integer>> itr=pinkpiece.iterator();
								while(itr.hasNext()){
									Tuple<Integer,Integer> pos=itr.next();
									unmarkPosition(pos.x,pos.y);
								}
							}
							//reset pinkpiece
							pinkpiece.clear();
							//update check
							Piece[][] board=new Piece[8][8];
							for(int i=0;i<8;i++)
								for(int j=0;j<8;j++)
									board[i][j]=getIcon(i,j);
							if(wherePiece(w_king, board)!=null&&wherePiece(b_king, board)!=null){
								check_W=update_check(true,board);
								//update checkmate
								if(check_W)
									checkmate_W=update_checkmate(false);
								//update flags
								flag=false;
								isFirst=true;
								if(checkmate_W){
									setStatus("CHEKCMATE: BLACK WIN");
								}else{
									String input="WHITE's TURN";
									if(check_W) input+="/CHECK";
									setStatus(input);
								}
							}else if(wherePiece(w_king, board)==null){
								setStatus("BLACK WIN");
								win_B=true;
							}
							else{
								setStatus("WHITE WIN");
								win_W=true;
							}
						}else{//cancel
							//update flags
							isFirst=true;
							//unmark position
							if(pinkpiece.size()>0){
								Iterator<Tuple<Integer,Integer>> itr=pinkpiece.iterator();
								while(itr.hasNext()){
									Tuple<Integer,Integer> pos=itr.next();
									unmarkPosition(pos.x,pos.y);
								}
							}
							//reset pinkpiece
							pinkpiece.clear();
						}

					}
				}
				else{
					//WHITE's TURN
					if(isFirst){
						//1.mark pink pieces
						if(getIcon(x,y).color.equals(PlayerColor.white)){
							origin_x=x;
							origin_y=y;
							pinkpiece=PinkPiece(x,y,null);

							if(pinkpiece.size()>0){
								Iterator<Tuple<Integer, Integer>> itr=pinkpiece.iterator();
								while(itr.hasNext()){
									Tuple<Integer,Integer> pos=itr.next();
									markPosition(pos.x,pos.y);
								}
								isFirst=false;
							}
						}
					}else{
						//2.move into pink piece
						if(isPinkPiece(x,y,pinkpiece)){
							//	update piece
							setIcon(x,y,getIcon(origin_x,origin_y));
							setIcon(origin_x,origin_y,new Piece(PlayerColor.none,PieceType.none));
							//unmark position
							if(pinkpiece.size()>0){
								Iterator<Tuple<Integer,Integer>> itr=pinkpiece.iterator();
								while(itr.hasNext()){
									Tuple<Integer,Integer> pos=itr.next();
									unmarkPosition(pos.x,pos.y);
								}
							}
							//reset pinkpiece
							pinkpiece.clear();
							//update check
							Piece[][] board=new Piece[8][8];
							for(int i=0;i<8;i++)
								for(int j=0;j<8;j++)
									board[i][j]=getIcon(i,j);
							if(wherePiece(w_king, board)!=null&&wherePiece(b_king, board)!=null){
								check_B=update_check(false,board);
								//update checkmate
								if(check_B)
									checkmate_B=update_checkmate(true);
								//update flags
								isFirst=true;
								flag=true;
								if(checkmate_B){
									setStatus("CHEKCMATE: WHITE WIN");
								}else{
									String input="BLACK's TURN";
									if(check_B) input+="/CHECK";
									setStatus(input);
								}
							}else if(wherePiece(w_king, board)==null){
								setStatus("BLACK WIN");
								win_B=true;
							}
							else{
								setStatus("WHITE WIN");
								win_W=true;
							}
						}else{
							//update flags
							isFirst=true;
							//unmark position
							if(pinkpiece.size()>0){
								Iterator<Tuple<Integer,Integer>> itr=pinkpiece.iterator();
								while(itr.hasNext()){
									Tuple<Integer,Integer> pos=itr.next();
									unmarkPosition(pos.x,pos.y);
								}
							}
							//reset pinkpiece
							pinkpiece.clear();
						}
					}
				}//end of WHITE's TURN
			}
		}//end of ActionPerforemd();

	}

	void onInitiateBoard(){
		setStatus("BLACK's TURN");
		flag=isFirst=true;
		check_B=checkmate_B=check_W=checkmate_W=win_B=win_W=false;
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++) setIcon(i, j, new Piece());
		}
		setIcon(0, 0, new Piece(PlayerColor.black, PieceType.rook));
		setIcon(0, 1, new Piece(PlayerColor.black, PieceType.knight));
		setIcon(0, 2, new Piece(PlayerColor.black, PieceType.bishop));
		setIcon(0, 3, new Piece(PlayerColor.black, PieceType.queen));
		setIcon(0, 4, new Piece(PlayerColor.black, PieceType.king));
		setIcon(0, 5, new Piece(PlayerColor.black, PieceType.bishop));
		setIcon(0, 6, new Piece(PlayerColor.black, PieceType.knight));
		setIcon(0, 7, new Piece(PlayerColor.black, PieceType.rook));
		for(int i=0;i<8;i++){
			setIcon(1, i, new Piece(PlayerColor.black, PieceType.pawn));
			setIcon(6, i, new Piece(PlayerColor.white, PieceType.pawn));
		}
		setIcon(7, 0, new Piece(PlayerColor.white, PieceType.rook));
		setIcon(7, 1, new Piece(PlayerColor.white, PieceType.knight));
		setIcon(7, 2, new Piece(PlayerColor.white, PieceType.bishop));
		setIcon(7, 3, new Piece(PlayerColor.white, PieceType.queen));
		setIcon(7, 4, new Piece(PlayerColor.white, PieceType.king));
		setIcon(7, 5, new Piece(PlayerColor.white, PieceType.bishop));
		setIcon(7, 6, new Piece(PlayerColor.white, PieceType.knight));
		setIcon(7, 7, new Piece(PlayerColor.white, PieceType.rook));
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++) unmarkPosition(i, j);
		}

	}
//===============================================Defined Methods===========================//
	boolean isPinkPiece(int x, int y, Set<Tuple<Integer,Integer>> set){
		if(set.size()==0) return false;
		Iterator<Tuple<Integer,Integer>> itr=set.iterator();
		while(itr.hasNext()){
			Tuple<Integer,Integer> pos=itr.next();
			if(x==pos.x&&y==pos.y) return true;
		}
		return false;
	}

	Set<Tuple<Integer,Integer>> PinkPiece(int x,int y, Piece[][] foo){
		Piece[][] board=new Piece[8][8];
		Piece piece;
		if(foo==null){
			for(int i=0;i<8;i++)
				for(int j=0;j<8;j++)
					board[i][j]=getIcon(i,j);
		}
		else
			board=foo;
		piece=board[x][y];
		
		PlayerColor mycolor=piece.color;
		Set<Tuple<Integer,Integer>> set=new HashSet<Tuple<Integer,Integer>>();
		Tuple<Integer,Integer> position=new Tuple<Integer,Integer>(x,y);
		//my team's piece exists: do not
		//outside of chess board: do not
		//opponent's piece exists: do
		if(piece.type.equals(PieceType.king)){
			if(position.x+1<8&&position.y+1<8)
				if(!board[position.x+1][position.y+1].color.equals(mycolor))
					set.add(new Tuple<Integer,Integer>(position.x+1,position.y+1));
			if(position.x+1<8)
				if(!board[position.x+1][position.y].color.equals(mycolor))
					set.add(new Tuple<Integer,Integer>(position.x+1,position.y));
			if(position.x+1<8&&position.y-1>=0)
				if(!board[position.x+1][position.y-1].color.equals(mycolor))
				set.add(new Tuple<Integer,Integer>(position.x+1,position.y-1));
			if(position.y-1>=0)
				if(!board[position.x][position.y-1].color.equals(mycolor))
					set.add(new Tuple<Integer,Integer>(position.x,position.y-1));
			if(position.x-1>=0&&position.y-1>=0)
				if(!board[position.x-1][position.y-1].color.equals(mycolor))
				set.add(new Tuple<Integer,Integer>(position.x-1,position.y-1));
			if(position.x-1>=0)
				if(!board[position.x-1][position.y].color.equals(mycolor))
					set.add(new Tuple<Integer,Integer>(position.x-1,position.y));
			if(position.x-1>=0&&position.y+1<8)
				if(!board[position.x-1][position.y+1].color.equals(mycolor))
					set.add(new Tuple<Integer,Integer>(position.x-1,position.y+1));
			if(position.y+1<8)
				if(!board[position.x][position.y+1].color.equals(mycolor))
					set.add(new Tuple<Integer,Integer>(position.x,position.y+1));
		}else if(piece.type.equals(PieceType.queen)){
			int xx=position.x;
			int yy=position.y;
			while(++xx<8&&++yy<8){
				if(board[xx][yy].color.equals(PlayerColor.none))
					set.add(new Tuple<Integer,Integer>(xx,yy));
				else{
					if(!board[xx][yy].color.equals(mycolor))
						set.add(new Tuple<Integer,Integer>(xx,yy));
					break;
				}
			}
			xx=position.x; yy=position.y;
			while(++xx<8){
				if(board[xx][yy].color.equals(PlayerColor.none))
					set.add(new Tuple<Integer,Integer>(xx,yy));
				else{
					if(!board[xx][yy].color.equals(mycolor))
						set.add(new Tuple<Integer,Integer>(xx,yy));
					break;
				}
			}
			xx=position.x; yy=position.y;
			while(++xx<8&&--yy>=0){
				if(board[xx][yy].color.equals(PlayerColor.none))
					set.add(new Tuple<Integer,Integer>(xx,yy));
				else{
					if(!board[xx][yy].color.equals(mycolor))
						set.add(new Tuple<Integer,Integer>(xx,yy));
					break;
				}
			}
			xx=position.x; yy=position.y;
			while(--yy>=0)
				if(board[xx][yy].color.equals(PlayerColor.none))
					set.add(new Tuple<Integer,Integer>(xx,yy));
				else{
					if(!board[xx][yy].color.equals(mycolor))
						set.add(new Tuple<Integer,Integer>(xx,yy));
					break;
				}
			xx=position.x; yy=position.y;
			while(--xx>=0&&--yy>=0)
				if(board[xx][yy].color.equals(PlayerColor.none))
					set.add(new Tuple<Integer,Integer>(xx,yy));
				else{
					if(!board[xx][yy].color.equals(mycolor))
						set.add(new Tuple<Integer,Integer>(xx,yy));
					break;

				}
			xx=position.x; yy=position.y;
			while(--xx>=0)
				if(board[xx][yy].color.equals(PlayerColor.none))
					set.add(new Tuple<Integer,Integer>(xx,yy));
				else{
					if(!board[xx][yy].color.equals(mycolor))
						set.add(new Tuple<Integer,Integer>(xx,yy));
					break;
				}

			xx=position.x; yy=position.y;
			while(--xx>=0&&++yy<8)
				if(board[xx][yy].color.equals(PlayerColor.none))
					set.add(new Tuple<Integer,Integer>(xx,yy));
				else{
					if(!board[xx][yy].color.equals(mycolor))
						set.add(new Tuple<Integer,Integer>(xx,yy));
					break;
				}
			xx=position.x; yy=position.y;
			while(++yy<8)
				if(board[xx][yy].color.equals(PlayerColor.none))
					set.add(new Tuple<Integer,Integer>(xx,yy));
				else{
					if(!board[xx][yy].color.equals(mycolor))
						set.add(new Tuple<Integer,Integer>(xx,yy));
					break;
				}
			xx=position.x; yy=position.y;
		}else if(piece.type.equals(PieceType.bishop)){

			int xx=position.x;
			int yy=position.y;
			while(++xx<8&&++yy<8)
				if(board[xx][yy].color.equals(PlayerColor.none))
					set.add(new Tuple<Integer,Integer>(xx,yy));
				else{
					if(!board[xx][yy].color.equals(mycolor))
						set.add(new Tuple<Integer,Integer>(xx,yy));
					break;
				}
			xx=position.x; yy=position.y;
			while(++xx<8&&--yy>=0)
				if(board[xx][yy].color.equals(PlayerColor.none))
					set.add(new Tuple<Integer,Integer>(xx,yy));
				else{
					if(!board[xx][yy].color.equals(mycolor))
						set.add(new Tuple<Integer,Integer>(xx,yy));
					break;
				}

			xx=position.x; yy=position.y;
			while(--xx>=0&&--yy>=0)
				if(board[xx][yy].color.equals(PlayerColor.none))
					set.add(new Tuple<Integer,Integer>(xx,yy));
				else{
					if(!board[xx][yy].color.equals(mycolor))
						set.add(new Tuple<Integer,Integer>(xx,yy));
					break;
				}
			xx=position.x; yy=position.y;
			while(--xx>=0&&++yy<8)
				if(board[xx][yy].color.equals(PlayerColor.none))
					set.add(new Tuple<Integer,Integer>(xx,yy));
				else{
					if(!board[xx][yy].color.equals(mycolor))
						set.add(new Tuple<Integer,Integer>(xx,yy));
					break;
				}

		}else if(piece.type.equals(PieceType.knight)){
			int xx=position.x;
			int yy=position.y;
			if(yy+2<8){
				if(xx-1>=0&&!board[xx-1][yy+2].color.equals(mycolor))
					set.add(new Tuple<Integer,Integer>(xx-1,yy+2));
				if(xx+1<8&&!board[xx+1][yy+2].color.equals(mycolor))
					set.add(new Tuple<Integer,Integer>(xx+1,yy+2));
			}
			if(yy-2>=0){
				if(xx-1>=0&&!board[xx-1][yy-2].color.equals(mycolor))
					set.add(new Tuple<Integer,Integer>(xx-1,yy-2));
				if(xx+1<8&&!board[xx+1][yy-2].color.equals(mycolor))
					set.add(new Tuple<Integer,Integer>(xx+1,yy-2));
			}
			if(xx+2<8){
				if(yy+1<8&&!board[xx+2][yy+1].color.equals(mycolor))
					set.add(new Tuple<Integer,Integer>(xx+2,yy+1));
				if(yy-1>=0&&!board[xx+2][yy-1].color.equals(mycolor))
					set.add(new Tuple<Integer,Integer>(xx+2,yy-1));
			}
			if(xx-2>=0){
				if(yy+1<8&&!board[xx-2][yy+1].color.equals(mycolor))
					set.add(new Tuple<Integer,Integer>(xx-2,yy+1));
				if(yy-1>=0&&!board[xx-2][yy-1].color.equals(mycolor))
					set.add(new Tuple<Integer,Integer>(xx-2,yy-1));
			}

		}else if(piece.type.equals(PieceType.rook)){
			int xx=position.x;
			int yy=position.y;
			while(++xx<8)
				if(board[xx][yy].color.equals(PlayerColor.none))
					set.add(new Tuple<Integer,Integer>(xx,yy));
				else{
					if(!board[xx][yy].color.equals(mycolor))
						set.add(new Tuple<Integer,Integer>(xx,yy));
					break;
				}
			xx=position.x;
			while(++yy<8)
				if(board[xx][yy].color.equals(PlayerColor.none))
					set.add(new Tuple<Integer,Integer>(xx,yy));
				else{
					if(!board[xx][yy].color.equals(mycolor))
						set.add(new Tuple<Integer,Integer>(xx,yy));
					break;
				}
			yy=position.y;
			while(--yy>=0)
				if(board[xx][yy].color.equals(PlayerColor.none))
					set.add(new Tuple<Integer,Integer>(xx,yy));
				else{
					if(!board[xx][yy].color.equals(mycolor))
						set.add(new Tuple<Integer,Integer>(xx,yy));
					break;
				}
			yy=position.y;
			while(--xx>=0)
				if(board[xx][yy].color.equals(PlayerColor.none))
					set.add(new Tuple<Integer,Integer>(xx,yy));
				else{
					if(!board[xx][yy].color.equals(mycolor))
						set.add(new Tuple<Integer,Integer>(xx,yy));
					break;
				}
			xx=position.x;

		}else if(piece.type.equals(PieceType.pawn)){
			int xx=position.x;
			int yy=position.y;
			if(mycolor.equals(PlayerColor.black)){
				if(position.x.intValue()==1){//initial
					if(xx+1<8){
						if(yy-1>=0&&board[xx+1][yy-1].color.equals(PlayerColor.white)){
							set.add(new Tuple<Integer,Integer>(xx+1,yy-1));
						}
						if(yy+1<8&&board[xx+1][yy+1].color.equals(PlayerColor.white)){
							set.add(new Tuple<Integer,Integer>(xx+1,yy+1));
						}
					}
					
					if(board[xx+1][yy].color.equals(PlayerColor.none)){
						set.add(new Tuple<Integer,Integer>(xx+1,yy));
						if(board[xx+2][yy].color.equals(PlayerColor.none))
						set.add(new Tuple<Integer,Integer>(xx+2,yy));
					}
				}else if(position.x<7){

					if(xx+1>=0){
						if(yy-1>=0&&board[xx+1][yy-1].color.equals(PlayerColor.white)){
							set.add(new Tuple<Integer,Integer>(xx+1,yy-1));
						}
						if(yy+1<8&&board[xx+1][yy+1].color.equals(PlayerColor.white)){
							set.add(new Tuple<Integer,Integer>(xx+1,yy+1));
						}
					}
					if(board[xx+1][yy].color.equals(PlayerColor.none))
						set.add(new Tuple<Integer,Integer>(xx+1,yy));
				}else ;

			}else{//mycolor.equals(PlayerColor.white)
				
				if(position.x.intValue()==6){//initial

					if(xx-1>=0){
						if(yy-1>=0&&board[xx-1][yy-1].color.equals(PlayerColor.black)){
							set.add(new Tuple<Integer,Integer>(xx-1,yy-1));
						}
						if(yy+1<8&&board[xx-1][yy+1].color.equals(PlayerColor.black)){
							set.add(new Tuple<Integer,Integer>(xx-1,yy+1));
						}
					}
					
					if(board[xx-1][yy].color.equals(PlayerColor.none)){
						set.add(new Tuple<Integer,Integer>(xx-1,yy));
						if(board[xx-2][yy].color.equals(PlayerColor.none))
							set.add(new Tuple<Integer,Integer>(xx-2,yy));
					}
					
				}else if(position.x>0){

					if(xx-1>=0){
						if(yy-1>=0&&board[xx-1][yy-1].color.equals(PlayerColor.black)){
							set.add(new Tuple<Integer,Integer>(xx-1,yy-1));
						}
						if(yy+1<8&&board[xx-1][yy+1].color.equals(PlayerColor.black)){
							set.add(new Tuple<Integer,Integer>(xx-1,yy+1));
						}
					}
					if(board[xx-1][yy].color.equals(PlayerColor.none))
						set.add(new Tuple<Integer,Integer>(xx-1,yy));
				}else ;
			}
		}else return null;
		return set;
	}

	Tuple<Integer,Integer> wherePiece(Piece piece, Piece[][] board){
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(board[i][j].color.equals(piece.color)&&board[i][j].type.equals(piece.type))
					return new Tuple<Integer,Integer>(i,j);
			}
		}
		return null;//the piece is dead
	}

	boolean update_check(boolean isBlack, Piece[][] board){
		PlayerColor mycolor=PlayerColor.black;
		Piece king=new Piece(PlayerColor.white,PieceType.king);
		if(!isBlack){
			mycolor=PlayerColor.white;
			king.color=PlayerColor.black;
		}
		Tuple<Integer,Integer> pos_king=wherePiece(king, board);

		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(board[i][j].color.equals(mycolor)){
					Set<Tuple<Integer,Integer>>tmp =PinkPiece(i,j,board);
					if(tmp==null) continue;
					Iterator<Tuple<Integer,Integer>> itr_tmp=tmp.iterator();
					while(itr_tmp.hasNext()){
						Tuple<Integer,Integer> pos_piece=itr_tmp.next();
						if(pos_king.x.intValue()==pos_piece.x.intValue()&&pos_king.y.intValue()==pos_piece.y.intValue())
							return true;
					}
				}
			}
		}//end of for loop
		return false;
	}
	boolean update_checkmate(boolean isBlack){
		Piece[][] board=new Piece[8][8];
		Set<Tuple<Integer,Integer>> myteam=new HashSet<Tuple<Integer,Integer>>();
		if(isBlack){
			for(int i=0;i<8;i++)
				for(int j=0;j<8;j++)
					if(getIcon(i,j).color.equals(PlayerColor.black))
						myteam.add(new Tuple<Integer,Integer>(i,j));
		}else{//isWHITE
			for(int i=0;i<8;i++)
				for(int j=0;j<8;j++)
					if(getIcon(i,j).color.equals(PlayerColor.white))
						myteam.add(new Tuple<Integer,Integer>(i,j));
		}
		if(myteam.size()==0)return true;

		Iterator<Tuple<Integer,Integer>> itr_myteam =myteam.iterator();
		while(itr_myteam.hasNext()){
			Tuple<Integer,Integer> pos=itr_myteam.next();
			Set<Tuple<Integer,Integer>> tmp=PinkPiece(pos.x,pos.y,null);

			if(tmp.size()==0) continue;
			Iterator<Tuple<Integer,Integer>> itr_tmp=tmp.iterator();
			while(itr_tmp.hasNext()){
				for(int i=0;i<8;i++)
					for(int j=0;j<8;j++)
						board[i][j]=getIcon(i,j);
				Tuple<Integer,Integer> tmp_pos=itr_tmp.next();
				board[tmp_pos.x][tmp_pos.y]=getIcon(pos.x,pos.y);
				board[pos.x][pos.y]=new Piece(PlayerColor.none,PieceType.none);
				
				if(!update_check(!isBlack, board)){
					return false;
				}

			}
		}
		return true;
	}
}
