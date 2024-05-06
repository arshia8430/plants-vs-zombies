



class obj{
	protected:
		int health;
		int x,y;
		Image image; 
	public:
		obj(int X,int Y,Image i,int h=0);
		void move(int dx,int dy);
		void change_image(Image i);
};

class GAME{
	private:
		vector <sun> suns;
		vector <flower> flowers;
		vector <zombie> zombies;
		vector <dart> darts;
		vector
		Window window;
	public:
		void start();


};

void GAME::start(){
	//set up game
	while (true){
		//if game==end then exit
		//if right click to flower && !flag then mouseImage==flower flag=true
		//if left click && flag then delete mouse image  flag=false
		//if right click && flag then checkmouse postion
	}


}