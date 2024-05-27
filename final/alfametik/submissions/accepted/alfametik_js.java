import java.util.Arrays;
import java.util.Scanner;

public class alfametik_js {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		wordCount = sc.nextInt();
		char[][] words = new char[wordCount+1][];
		for(int i = 0; i<=wordCount; i++){
			words[i] = sc.next().toCharArray();
			nozero[words[i][0]] = true;
			int length = words[i].length;
			for(int j = 0; j< length /2; j++) {
				char tmp = words[i][j];
				words[i][j] = words[i][length -1-j];
				words[i][length -1-j] = tmp;
			}
		}
		int chars = 0;
		for(int i = 0; i<8; i++){
			boolean keep = false;
			for (char[] word : words){
				if(word.length <= i) continue;
				keep = true;
				for(int j = 0; j<=chars; j++){
					if(order[j] == word[i]) break;
					if(order[j] == 0){
						order[j] = word[i];
						chars++;
						break;
					}
				}
			}
			if(!keep) break;
			order[chars++] = 1;
		}
		Arrays.fill(mapping, -1);
		rec(words, 0, 0, 0);
	}

	private static int wordCount;
	private static char[] order = new char[21];
	private static boolean[] used = new boolean[10];
	private static int[] mapping = new int[128];
	private static boolean[] nozero = new boolean[128];

	private static void rec(char[][] words, int at, int col, int sum){
		if(order[at] == 1){
			//Kolla om det överrenstämmer
			int expected = mapping[words[wordCount][col]];
			if(sum%10 != expected){
				return;
			}
			sum /= 10;
			for(int i = 0; i<wordCount; i++){
				char[] word = words[i];
				if(word.length <= col+1) continue;
				if(mapping[word[col+1]] != -1){
					sum += mapping[word[col+1]];
				}
			}
			rec(words, at+1, col+1, sum);
		} else if(order[at] == 0){
			for(int i = 0; i<=wordCount; i++){
				for(int j = words[i].length-1; j >= 0; j--){
					System.out.print(mapping[words[i][j]]);
				}
				System.out.println();
			}
			System.exit(0);
		} else {
			for(int i = 0; i<10; i++){
				if(!used[i] && (i != 0 || !nozero[order[at]])){
					mapping[order[at]]  = i;
					used[i] = true;
					int nsum = sum;
					for(int j = 0; j<wordCount; j++){
						char[] word = words[j];
						if(word.length <= col) continue;
						if(word[col] == order[at]){
							nsum += mapping[word[col]];
						}
					}
					rec(words, at+1, col, nsum);
					mapping[order[at]]  = -1;
					used[i] = false;
				}
			}
		}
	}

}

