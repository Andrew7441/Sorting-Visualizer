#include<iostream>
#include<vector>
#include "raylib.h"
#include <random>

using namespace std;

class SortingVisualizer{
private:

	vector<double> vec{};
	const int MAX_SIZE{100};
	const int HEIGHT {800};
	const int WIDTH {800};

	//sort step by step
	int i{0};
	int j{1};
	int k{0};
	bool sorted{false};



public:
	SortingVisualizer(){
		InitWindow(WIDTH, HEIGHT, "Sorting Visualizer");
		SetTargetFPS(60);

		std::mt19937 generator {};
		std::uniform_real_distribution<double> range {0.0, 1.0};

		for(i = 0; i < MAX_SIZE; i++){
			vec.push_back(range(generator)); // generate random #
		}
	}

	void run(){
		while(!WindowShouldClose()){
			PollInputEvents();

			for(int i = 0; i < 50; i++){
				sort();
			}

			BeginDrawing();
			draw_array();
			EndDrawing();

			ClearBackground(BLACK);
		}
	}

	void draw_array() {
		size_t x_step{ WIDTH / MAX_SIZE };

		for(i = 0; i < MAX_SIZE; i++){
			int height_rect = static_cast<int>(vec[i] * HEIGHT * 0.9);
			auto color { sorted ?  GREEN : WHITE};
			DrawRectangle(x_step * i, HEIGHT - height_rect, x_step, height_rect, color); 
		}
	}

	void sort(){
		if(sorted) return;

		if(i >= vec.size() - 1){
			sorted = true;
			return;
		}

		if(j < vec.size()){
			if(vec[j] < vec[k]){
				k = j;
			}

			j++;
		}else{
			swap(vec[i], vec[k]);

			i++;
			k = i;
			j = i + 1;
		}

	}
};


int main(){
	SortingVisualizer instance {};

	instance.run();

	return 0;
}