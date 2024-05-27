#include <stdio.h>
#include <stdlib.h>


int x1[50], x2[50], y1[50], y2[50], x[100], y[100];
int a,b,c,d,e, ant,X,Y, nx, ny, max, ar;
char tagen[100][100], hor[100][100], ver[100][100];

void MLX(int xx, int yy) {
	if(tagen[xx][yy]) return;
	tagen[xx][yy] = 1;
	ar += (x[xx+1] - x[xx]) * (y[yy+1] - y[yy]);
	if(!ver[xx][yy]) MLX(xx-1, yy);
	if(!ver[xx+1][yy]) MLX(xx+1, yy);
	if(!hor[yy][xx]) MLX(xx, yy-1);
	if(!hor[yy+1][xx]) MLX(xx, yy+1);
}


int main() {
	scanf("%d %d %d", &X, &Y, &ant);
	nx = ny = 0;
	for(a=0;a<ant;a++) {
		scanf("%d %d %d %d", &x1[a], &y1[a], &x2[a], &y2[a]);
		if(x1[a] > x2[a]) b = x1[a], x1[a] = x2[a], x2[a] = b;
		if(y1[a] > y2[a]) b = y1[a], y1[a] = y2[a], y2[a] = b;

		for(b=0;b<ny;b++) if(y1[a] == y[b]) break;
		if(b==ny) {
			for(b=ny;b>=0;b--) {
				if(y1[a] > y[b-1]) break;
				else y[b] = y[b-1];
			}
			y[b] = y1[a];
			ny++;
		}

		for(b=0;b<ny;b++) if(y2[a] == y[b]) break;
		if(b==ny) {
			for(b=ny;b>=0;b--) {
				if(y2[a] > y[b-1]) break;
				else y[b] = y[b-1];
			}
			y[b] = y2[a];
			ny++;
		}

		for(b=0;b<nx;b++) if(x1[a] == x[b]) break;
		if(b==nx) {
			for(b=nx;b>=0;b--) {
				if(x1[a] > x[b-1]) break;
				else x[b] = x[b-1];
			}
			x[b] = x1[a];
			nx++;
		}

		for(b=0;b<ny;b++) if(x2[a] == x[b]) break;
		if(b==nx) {
			for(b=nx;b>=0;b--) {
				if(x2[a] > x[b-1]) break;
				else x[b] = x[b-1];
			}
			x[b] = x2[a];
			nx++;
		}
	}
	for(a=0;a<=nx;a++) for(b=0;b<=ny;b++) {
		ver[a][b] = hor[a][b] = 0;
		tagen[a][b] = 0;
	}
	for(a=0;a<ant;a++) {
		if(x1[a] == x2[a]) {  //Vertical
			for(b=0;x[b]!=x1[a];b++);
			for(c=0;y[c]!=y1[a];c++);
			for(d=0;y[d]!=y2[a];d++);
			for(e=c;e<d;e++) ver[b][e] = 1;
		}
		else {
			for(b=0;y[b]!=y1[a];b++);
			for(c=0;x[c]!=x1[a];c++);
			for(d=0;x[d]!=x2[a];d++);
			for(e=c;e<d;e++) hor[b][e] = 1;
		}
	}
	max = 0;
	for(a=0;a<nx-1;a++) for(b=0;b<ny-1;b++)	{
		ar = 0;
		MLX(a, b);
		if(ar > 0) {
			//printf("%ld ", ar);
			if(ar > max) max = ar;
		}
	}
	printf("%d\n", max);
        return 0;
}


