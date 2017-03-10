package springSpiel;

public class Turn {
	int m_x;
	int m_y;
	String m_direction;
	
	public Turn(int x, int y, String direction){
		m_x = x;
		m_y = y;
		m_direction = direction;
	}
	
	public int getX(){
		return m_x;
	}
	
	public int getY(){
		return m_y;
	}
	
	public String getDirection(){
		return m_direction;
	}
}
