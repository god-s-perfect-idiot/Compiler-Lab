#include<stdio.h>
#include<string.h>

int n,fin[100],nd,parent=999,k;
char nfa[100][100],alph[10000],c;
int path[100];



void pcl(int node){

	for(int i=0;i<n;i++){
	
		int unique = 1;
		if(nfa[node][i]=='e'){
			if(i==node){
				for(int l=0;l<k;l++){
					if(node==path[l]){
						unique=0;	
					}
				}
				if(unique){
					path[k]=node;
					k+=1;
				}	
			}
			else if(i==parent){
				for(int l=0;l<k;l++){
					if(parent==path[l]){
						unique=0;	
					}
				}
				if(unique){
					path[k]=parent;
					k+=1;
				}
			}
			else{
				for(int l=0;l<k;l++){
					if(i==path[l]){
						unique=0;	
					}
				}
				if(unique){
					path[k]=i;
					k+=1;
				}
				parent=node;
				pcl(i);
			}
		}
	
	}

}

void main(){

	printf("Enter number of states:");
	scanf("%d",&n);
	
	k=0;
	for(int i=0;i<n;i++){
		
		for(int j=0;j<n;j++){
		
			printf("Edge q%d -> q%d:",i,j);			
			scanf(" %c",&c);
			int unique=1;
			for(int l=0;l<k;l++){
				if(c==alph[l]){
					unique=0;	
				}
			}
			if(unique){
				alph[k] = c;
				k=k+1;
			}
			nfa[i][j]=c;
			
		}
		
	}
	
	while(1){
		printf("check e-closure of node:");
		scanf(" %d",&nd);
		pcl(nd);
		for(int i=0;i<k;i++){
			printf("%d \n",path[i]);
		}
		k=0;
		parent=999;
	}
	
}
