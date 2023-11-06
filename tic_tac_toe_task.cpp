#include<bits/stdc++.h>
using namespace std;
class Game
{
public:

	string board[9]={" "," "," "," "," "," "," "," "," "};

    
    // displaying board
	void getboard(){
		cout<<"   "<<" |"<<"   "<<" |"<<"   "<<endl;
		cout<<" "<<board[0]<<" "<<" |"<<" "<<board[1]<<" "<<" |"<<" "<<board[2]<<" "<<endl;
		cout<<"   "<<" |"<<"   "<<" |"<<"   "<<endl;
		cout<<"---------------"<<endl;
		cout<<"   "<<" |"<<"   "<<" |"<<"   "<<endl;
		cout<<" "<<board[3]<<" "<<" |"<<" "<<board[4]<<" "<<" |"<<" "<<board[5]<<" "<<endl;
		cout<<"   "<<" |"<<"   "<<" |"<<"   "<<endl;
		cout<<"---------------"<<endl;
		cout<<"   "<<" |"<<"   "<<" |"<<"   "<<endl;
		cout<<" "<<board[6]<<" "<<" |"<<" "<<board[7]<<" "<<" |"<<" "<<board[8]<<" "<<endl;
		cout<<"   "<<" |"<<"   "<<" |"<<"   "<<endl;
	}



	// getting winner
	string getwinner(){

        // checking horizontally row wise
		if(board[0]==board[1] && board[1]==board[2] && board[0]!=" "){
			return board[0];
		}
		if(board[3]==board[4] && board[4]==board[5]&& board[3]!=" "){
			return board[3];
		}
		if(board[6]==board[7] && board[7]==board[8] && board[6]!=" "){
			return board[6];
		}

        
        // checking winner vertically column wise
		if(board[0]==board[3] && board[3]==board[6] && board[0]!=" "){
			return board[0];
		}
		if(board[1]==board[4] && board[4]==board[7]&& board[1]!=" "){
			return board[1];
		}
		if(board[2]==board[5] && board[5]==board[8] && board[2]!=" "){
			return board[2];
		}


		// checking diagonal wise
		if(board[0]==board[4] && board[4]==board[8] && board[0]!=" "){
			return board[0];
		}
		if(board[2]==board[4] && board[4]==board[6]&& board[2]!=" "){
			return board[2];
		}

		if(count("X")+count("O") < 9){
			return "cont";
		}
		else{
			return "draw";
		}

	}



	// counting the filled positions of X or O to continue game or to end
	int count(string s){
    	int t=0;
    	for(int i=0;i<9;i++){
    		if(board[i]==s){
    			t=t+1;
    		}
    	}
    	return t;
    }


    // getting player X choice
    void get_Player1_choice(){
		while(flag==1){
			cout<<"select your Position (1-9) : ";
			int choice;
			cin>>choice;
			choice--; //because 0-based indexing
			if(choice<0 || choice>8){
				cout<<"Invalid choice please try again !"<<endl;
			}
			else if(board[choice]!=" "){
				cout<<"Invalid choice please select empty position !"<<endl;
			}
			else{
				board[choice]='X';
				flag=0;
				break;
			}
		}
	}












};



class Player:
{
public:
	string player1;
	string player2;

	void getplayername(string p1,string p2)
	{
		player1=p1;
		player2=p2;
	}
	

};

int main(){


	string p1,p2;
	cout<<"enter X player name : "<<endl;
	cout<<"enter O player name : "<<endl;

	cin>>p1;
	cin>>p2;


	Player pl1;
	pl1.getplayername(p1,p2);


	// Game g1;
	// g1.getboard();
	// return 0;
}