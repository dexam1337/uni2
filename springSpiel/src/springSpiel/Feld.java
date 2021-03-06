package springSpiel;

public class Feld {
	private Punkt[][] field;
	private int turn = 0;
	private int pieces;

	Feld() {
		pieces = 0;
		field = new Punkt[7][7];
		for (int i = 0; i < field.length; i++) {
			for (int j = 0; j < field.length; j++) {
				if ((i < 2 || i > 4) && (j < 2 || j > 4)) {
					field[i][j] = null;
					// System.out.print("0");
				} else {
					pieces++;
					if (i == 3 && j == 3) {
						field[i][j] = new Punkt(i, j, false);
					} else {
						field[i][j] = new Punkt(i, j);
					} // System.out.print("X");
				}
			}
			System.out.println();
		}
	}

	void printField() {
		System.out.println("Zug Nr." + turn + ".");
		System.out.println((pieces - 1) + " Steine m\u00fcssen noch entfernt werden.");
		System.out.println("-----------------------------");
		for (int i = 0; i < field.length; i++) {
			for (int j = 0; j < field.length; j++) {
				if ((i < 2 || i > 4) && (j < 2 || j > 4)) {
					System.out.print("|   ");
				} else {
					if (field[i][j].getBlocked()) {
						System.out.print("| O ");
					} else {
						System.out.print("|   ");
					}
				}
			}
			System.out.print("|");
			System.out.println();
			System.out.println("-----------------------------");
		}

		if (pieces == 1) {
			System.out.println("Herzlichen Glückwunsch! Gewonnen!");
		}
	}

	public boolean getBlocked(int x, int y) {

		return field[x][y].getBlocked();
	}

	boolean jump(int x, int y, String direction) {

		// printField();
		if ((x < 2 || x > 4) && (y < 2 || y > 4) || x < 0 || x > 7 || y < 0 || y > 7) {
			System.out.println("Start is out of Area");
			return false;
		}

		switch (direction) {
		case "LINKS":

			if (isFree(x, y) == false && isFree(x, y - 1) == false && isFree(x, y - 2)) {
				field[x][y].toogleState();
				field[x][y - 1].toogleState();
				field[x][y - 2].toogleState();
				turn++;
				pieces--;
				return true;
			} else {
				return false;
			}
		case "RECHTS":
			if (isFree(x, y) == false && isFree(x, y + 1) == false && isFree(x, y + 2)) {
				field[x][y].toogleState();
				field[x][y + 1].toogleState();
				field[x][y + 2].toogleState();
				turn++;
				pieces--;
				return true;
			} else {
				return false;
			}
		case "HOCH":
			if (isFree(x, y) == false && isFree(x - 1, y) == false && isFree(x - 2, y)) {
				field[x][y].toogleState();
				field[x - 1][y].toogleState();
				field[x - 2][y].toogleState();
				turn++;
				pieces--;
				return true;
			} else {
				return false;
			}
		case "RUNTER":
			if (isFree(x, y) == false && isFree(x + 1, y) == false && isFree(x + 2, y)) {
				field[x][y].toogleState();
				field[x + 1][y].toogleState();
				field[x + 2][y].toogleState();
				turn++;
				pieces--;
				return true;
			} else {
				return false;
			}
		}
		return false;
	}

	boolean isFree(int x, int y) {
		if ((x < 2 || x > 4) && (y < 2 || y > 4) || x < 0 || x > 7 || y < 0 || y > 7) {
			return false;
		}
		if (field[x][y].getBlocked() == false) {
			return true;
		}
		return false;
	}

	int getTurn() {
		return turn;
	}

	int getPieces() {
		return pieces;
	}

	private void setTurn(int newTurn) {
		turn = newTurn;
	}

	private void setPieces(int newPiece) {
		pieces = newPiece;
	}
	
	private void tooglePiece(int x, int y){
		field[x][y].toogleState();
	}

	public Feld copy(){
		Feld output = new Feld();
		
		output.setTurn(turn);
		output.setPieces(pieces);
		
		for (int i = 0; i < field.length; i++) {
			for (int j = 0; j < field.length; j++) {
				if ((i < 2 || i > 4) && (j < 2 || j > 4)) {
					
				} else {
					if(!(output.isFree(i, j) == isFree(i,j))){
						output.tooglePiece(i,j);
					}
				}
			}
		}
		return output;
	}

}
