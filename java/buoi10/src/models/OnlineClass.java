package models;

import java.util.Scanner;

public class OnlineClass extends CClass {
    private String link = "";

    public OnlineClass() {}
    public OnlineClass(String _teacher, Time _timeStart, Time _timeEnd, String _link) {
        super(_teacher, _timeStart, _timeEnd);
        link = _link;
    }

    public void setLink(String link) {
        this.link = link;
    }
    public String getLink() {
        return link;
    }

    public void input() {
        super.input();
        Scanner sc = new Scanner(System.in);
        link = sc.next();
    }

    @Override
    public String toString() {
        return link;
    }
}
