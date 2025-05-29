package L04;

import java.util.LinkedList;
import java.util.ListIterator;

public class TestList {
    public static void main(String[] args) {
        LinkedList<Character> L = new LinkedList<>();
        L.add('d');
        L.add('m');
        L.add('i');
        L.add('h');

        ListIterator<Character> it = L.listIterator(L.size());
        System.out.println("it = " + it.previous());
        it.remove();
        for (Character c : L) {
            System.out.print(c);
        }
    }
}
