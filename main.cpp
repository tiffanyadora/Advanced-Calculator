#include <bits/stdc++.h>

using namespace std;

class mathObject{
	private:
		string type;
		double num;
		int pri;
	public:
		mathObject(string type = "", int pri = -1, double num = 0){
			this->type = type;
			this->num = num;
			this->pri = pri;
		}
		//GETTER
		string getType(){
			return this->type;
		};
		double getNum(){
			return this->num;
		}
		char getPri(){
			return this->pri;
		}
		//SETTER
		void setType(string type){
			this->type = type;
		}
		void setNum(double num){
			this->num = num;
		}
		void setPri(char pri){
			this->pri = pri;
		}
};

int solveRecursion(){
	
}

int main(){
	
    //cout<<"Tes" << endl;
    //cout << "cobain bosq" << endl;
    
    //GET USER INPUT
    string input;
    getline(cin, input);
    
    
    //CLEAN INPUT (remove spaces and toLowercase)
    for(int i = 0; i < input.length(); i++){
		if(input[i] == ' '){
			input.erase(i,1);
		}
		input[i] = tolower(input[i]);
	}
	
	cout << "clean input: " << input << endl;
	
	//INITIALIZE mathObject ARRAY
	mathObject arr[input.length()];
	
	
	// [ P A R S E R ] ==============================
	//COVERT string INPUT TO mathObject ARRAY 
	
	// > BRACKET TELEPORT SYSTEM
	int bracketDepth = 0;
	int bracketTeleportHandler[20];
	
	// > INITIALIZE LOOP VARIABLES
	
	int i = 0, //INDEX being worked on
		t = 0; //target INDEX of mathObject arr
		
	// > MAIN LOOP
    while(i < input.length()){
    	char cur = input[i];
    	if(cur == '('){
    		arr[t] = mathObject("bracket_open", 99);
    		bracketDepth++;
    		bracketTeleportHandler[bracketDepth] = t;
    		t++; i++;
    		
		}else if(cur == ')'){
    		arr[t] = mathObject("bracket_close", -1);
    		arr[bracketTeleportHandler[bracketDepth]].setNum(t);
    		bracketDepth--;
    		t++; i++;
    		
		}else if(cur == '^'){
			arr[t] = mathObject("power", 5);
    		t++; i++;
    		
		}else if(cur == '*'){
			arr[t] = mathObject("multiplication", 4);
    		t++; i++;
    		
		}else if(cur == '/'){
			arr[t] = mathObject("division", 3);
    		t++; i++;
    		
		}else if(cur == '+'){
			arr[t] = mathObject("addition", 2);
    		t++; i++;
    		
		}else if(cur == '-'){
			arr[t] = mathObject("substraction", 1);
    		t++; i++;
    		
		}else if('0' <= cur && cur <= '9'){
			double frontTemp = 0; //INFRONT OF COMA
			double backTemp = 0; // BACK OF COMA
			double behindComa = 0;
			while(true){
				
				if(input[i] == '.'){
					behindComa = 1;
				}else if(behindComa > 0){
					int toInt = input[i] - '0';
					backTemp = (backTemp*10) + toInt;
					behindComa++;
				}else{
					int toInt = input[i] - '0';
					frontTemp = (frontTemp*10) + toInt;
				}
				
				
				char nextInput = input[i+1];
				if((i+1) < input.length() && (('0' <= nextInput && nextInput <= '9') || nextInput == '.')){
					i++;
				}else{
					arr[t] = mathObject("number", -1, frontTemp+(backTemp/pow(10,behindComa-1)) );
					t++; i++;
					break;
				}
			}
			
		}else if('a' <= cur && cur <= 'z'){
			int startIn = i;
			while(true){
				char nextInput = input[i+1];
				if((i+1) < input.length() && ('a' <= nextInput && nextInput <= 'z')){
					i++;
				}else{
					string str = input.substr(startIn, i-startIn+1);
					if(str == "sin") arr[t] = mathObject("sin", 6);
					if(str == "cos") arr[t] = mathObject("cos", 6);
					if(str == "tan") arr[t] = mathObject("tan", 6);
					if(str == "log") arr[t] = mathObject("log", 6);
					if(str == "sqrt") arr[t] = mathObject("sqrt", 6);
					if(str == "ln") arr[t] = mathObject("ln", 6);
					
					t++; i++;
					break;
				}
			}
		}else{
			cout << "ERROR: UNRECOGNIZED INPUT" << endl;
			break;
		}
	}
    
    cout << endl;
    for(int a = 0; a < t; a++){
    	cout << arr[a].getType() << " " << setprecision(11) << arr[a].getNum() << endl;
	}
    return 0;
}
