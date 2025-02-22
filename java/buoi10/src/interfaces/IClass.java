package interfaces;

import java.util.ArrayList;
import models.*;

public interface IClass {
    ArrayList getAllClass();
    ArrayList getClassByTeacher(String name);
    ArrayList getClassByTime(Time time);
    void addClass(CClass c);
    void removeClass(CClass c);
}
