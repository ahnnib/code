import models.*;

public class App {
    public static void main(String[] args) {
        ClassManager M = new ClassManager();

        Time start = new Time(7, 0, 0);
        Time end = new Time(11, 0, 0);
        Time dup = new Time(11, 0, 0);

        System.out.print(start.compareTime(end) + " ");
        System.out.print(end.compareTime(start) + " ");
        System.out.println(end.compareTime(dup));
        System.out.println("---");
        // -1 1 0

        CClass c1 = new CClass("10A5", start, end);
        CClass c2 = new CClass("10A3", new Time(13, 0, 0), new Time(14, 0, 0));
        CClass c3 = new CClass("10B1", new Time(9, 0, 0), new Time(15, 0, 0));
        CClass c4 = new OfflineClass("10C1", start, new Time(17, 0, 0), "1 a b c");

        System.out.println(c1.equals(new CClass("10A5", start, new Time(11, 0, 0))));
        System.out.println("---");
        // true

        M.addClass(c1);
        M.addClass(c2);
        M.addClass(c3);
        M.addClass(c4);

        for (CClass c : M.getAllClass()) {
            System.out.println(c);
        }
        System.out.println("---");
        /*
        10A5, 7:0:0, 11:0:0
        10A3, 13:0:0, 14:0:0
        10B1, 9:0:0, 15:0:0
        1 a b c
        */

        for (CClass c : M.getClassByTeacher("10A3")) {
            System.out.println(c);
        }
        for (CClass c : M.getClassByTeacher("10C1")) {
            System.out.println(c);
        }
        System.out.println("---");
        /*
        10A3, 13:0:0, 14:0:0
        1 a b c
        */

        for (CClass c : M.getClassByTime(new Time(13, 0, 0))) {
            System.out.println(c);
        }
        System.out.println("---");
        /*
        10A3, 13:0:0, 14:0:0
        10B1, 9:0:0, 15:0:0
        1 a b c
        */

        M.removeClass(new CClass("10A3", new Time(13, 0, 0), new Time(14, 0, 0)));
        M.removeClass(new CClass("10B2", start, end));
        for (CClass c : M.getAllClass()) {
            System.out.println(c);
        }
        /*
        10A5, 7:0:0, 11:0:0
        10B1, 9:0:0, 15:0:0
        1 a b c
        */
    }
}
