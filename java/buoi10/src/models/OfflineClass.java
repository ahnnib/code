package models;

import java.util.Scanner;

public class OfflineClass extends CClass {
    public String address = "-";

    public OfflineClass() {}
    public OfflineClass(String _teacher, Time _timeStart, Time _timeEnd, String _address) {
        super(_teacher, _timeStart, _timeEnd);
        address = _address;
    }

    public String getAddress() {
        return address;
    }
    public void setAddress(String address) {
        this.address = address;
    }

    public void input() {
        Scanner sc = new Scanner(System.in);
        address = sc.nextLine();
    }

    @Override
    public String toString() {
        return address;
    }
}