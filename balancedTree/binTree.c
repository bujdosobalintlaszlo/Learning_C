#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	struct Node* leftNode_;
	struct Node* rightNode_;
	int payload_;
} node_t;

void insert(node_t **h, int n);
void print(node_t *);
void destroy(node_t *);
int main(){
	int n;
	node_t *head=NULL;
	//ha nem a cimet adnam at a valtozonak, akkor nem tudna modositani a valtozot, hiszen
	//masolatkent, ertekkent adjuk at a scanf-et
	// ha sikeres a beolvasas a scanf 1 et, has sikertelen 0 ad vissza
	while(1==scanf("%d",&n)){
		insert(&head,n);
	}
	/*
	TEST VOLT PRINTHEZ INSERT NELKUL
	//fej elem
	head = (node_t *)malloc(sizeof(node_t));
	head->payload_=5;
	//bal oldala a fanak
	head->leftNode_ = (node_t *)malloc(sizeof(node_t));
	head->leftNode_->payload=3;
	head->leftNode_-> left_Node = head->leftNode_->rightNode_ = NULL;

	//jobb oldala a fanak
	head->rightNode_ = (node_t *)malloc(sizeof(node_t));
	head->rightNode_->payload=8;
	head->rightNode_->leftNode_ = head->leftNode_->rightNode_ = NULL;
	*/
	print(head);

	//uritjuk a memoriat
	destroy(head);
}

//post order rekurzio kell a torleshez (bal reszfa, jobb reszfa, kurrens elem)
void destroy(node_t *root){
	if(root){
		destroy(root->leftNode_);
		destroy(root->rightNode_);
		free(root);
	}
}

//kiiras in order modszerrel
void print(node_t* root){
	/*
	 *elonyok: 
	 - sokkal tobb esetet "kibir" ertsd kiszur
	 - nem a mainben hivogatom, a logika szeparalt, a kod atlathatobb	
	 *hatrany:
	 - futasi hatekonysag szempontjabol nem feltetlen jo mert a NULL gyerekekre is
	 lefut.
	 konkl.:El kell donteni, hogy a hatekonysagot vagy a biztonsagot reszesitsuk elonyben.
	 (ITT MIND1)
	 * */
	if(root){
		print(root->leftNode_);
		printf("%d ",root->payload_);
		print(root->rightNode_);
	}
}


void insert(node_t **rootptr, int n){
	//ha volt elem eldontom, hogy kisebb vagy nagyobb a kurrens elemnel, 
	//ennek megfeleloen bal vagy jobb agra hivom meg az inertet (if ag)
	//    (3) <- itt vagyunk most
	//   /   \
	//  (4)  (5)
	//ha a pozicionk (3), akkor abban az esetben eseteben pl.: igy kell eljarni (if ga)
	if(*rootptr){
		//ez mar a pointer ami a ptr re mutat
		node_t *root = *rootptr;
		if(n < root->payload_){
			insert(&root->leftNode_,n);
		}else{
			insert(&root->rightNode_,n);
		}
	}
	//ha NULL az adott node amiben vagyuk beszurom oda a kapott n-t (else)-ag
	//else ag elott:
	//    (3)
	//   /   \
	//  (4)  (5)
	//  	/   \
	//    (N)   (N) <- itt vagyunk most
	//else ag utan
	//    (3)
	//   /   \
	//  (4)  (5)
	//      /   \
	//     (N)  (6) <- ide szurtuk n-t
	//         /   \
	//        (N)  (N) <- az ujonnan beszurt n NULL agai (reprezantativ csak) termeszetesen
	//4nel is ott van
	//ha a pozicionk NULL (N reprezentalja), akkor megfeleloen beszurjuk. Pl.: ha n=6 if agba 2szer leptunk 3nal es 5nel, majd 5nek a jobb oldali (N)be erkezunk. Ide rakjuk 5 es annak mind2 gyereket Nullra(N) allitjuk
	else{
		//ez csak az insertben levo head masolat
		*rootptr = malloc(sizeof(node_t));
		if(NULL==*rootptr){
			fprintf(stderr,"no memory\n");
			//exit bezarja a programot, es a parametere lesz a program exitkodja
			//ezt pl egy futtato python vagy shellscript ki tudja olvasni es ennek
			//megfeleloen el tudunk jarni
			exit(1);
		}
		node_t *root = *rootptr;
		root->payload_ = n;
		root->leftNode_ = root->rightNode_ = NULL;
	}
}
