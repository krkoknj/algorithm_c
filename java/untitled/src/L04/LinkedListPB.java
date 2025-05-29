package L04;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.ListIterator;

public class LinkedListPB {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 1) 초기 문자열 입력 받고 리스트로 변환
        String S = br.readLine();
        LinkedList<Character> L = new LinkedList<>();
        for (char c : S.toCharArray()) {
            L.add(c);
        }

        // 2) 커서를 리스트의 끝(= end()) 위치로 설정
        ListIterator<Character> it = L.listIterator(L.size());

        // 3) 명령 개수 읽고 한 줄씩 처리
        int M = Integer.parseInt(br.readLine());
        while (M-- > 0) {
            String line = br.readLine();
            char cmd = line.charAt(0);

            switch (cmd) {
                case 'P':
                    // "P x" → 커서 바로 앞에 x 삽입
                    char x = line.charAt(2);
                    it.add(x);
                    break;
                case 'L':
                    // "L" → 커서를 왼쪽으로 한 칸
                    if (it.hasPrevious()) {
                        it.previous();
                    }
                    break;
                case 'D':
                    // "D" → 커서를 오른쪽으로 한 칸
                    if (it.hasNext()) {
                        it.next();
                    }
                    break;
                case 'B':
                    // "B" → 커서 왼쪽의 문자 삭제
                    if (it.hasPrevious()) {
                        it.previous();
                        it.remove();
                    }
                    break;
                default:
                    // 그 외는 없음
            }
        }

        // 4) 결과 문자열 생성 및 출력
        StringBuilder sb = new StringBuilder(L.size());
        for (char c : L) {
            sb.append(c);
        }
        System.out.println(sb.toString());
    }
}
