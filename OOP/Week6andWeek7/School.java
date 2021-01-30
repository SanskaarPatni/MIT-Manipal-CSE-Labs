package com.course.structure;

import java.util.*;

public class School extends Building {

	int nClass;
	String grade;
	
	public void setClass (int nClass) {
		this.nClass = nClass;
	}

	public void setGrade (String grade) {
		this.grade = new String(grade);
	}

	public int getnClass () {
		return nClass;
	}

	public String getGrade () {
		return grade;
	}
}