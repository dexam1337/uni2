package springSpiel;

import java.util.Vector;

public class Solver {
	
	Vector<Feld> savedGames = new Vector<Feld>(10);
	Vector<Turn> usedTurns = new Vector<Turn>(10);
	Feld m_begin;
	public Solver(Feld begin){
		m_begin = begin;
	}

	public void worldRecord() throws InterruptedException{
		Thread.sleep(1000);
		m_begin.jump(3, 1, "RECHTS");
		Thread.sleep(1000);
		m_begin.jump(5, 2, "OBEN");
		Thread.sleep(1000);
		m_begin.jump(4, 0, "RECHTS");
		Thread.sleep(1000);
		m_begin.jump(4, 3, "LINKS");
		Thread.sleep(1000);
		m_begin.jump(4, 5, "LINKS");
		Thread.sleep(1000);
		m_begin.jump(6, 4, "OBEN");
		Thread.sleep(1000);
		m_begin.jump(3, 4, "UNTEN");
		Thread.sleep(1000);
		m_begin.jump(3, 1, "RECHTS");
		Thread.sleep(1000);
		m_begin.jump(3, 1, "RECHTS");
		Thread.sleep(1000);
		m_begin.jump(3, 1, "RECHTS");
		Thread.sleep(1000);
	}
}
