#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum State { FIRST, MATCH, NO_MATCH };

// To clear the screen, look up ANSI escape codes
// Concentration game model
// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    // Initialize a grid of letters randomly
    Model(int w, int h);
    // Destructor deletes all dynamically allocated stuff
    ~Model();
    // Methods (member functions)
    // Return the width
    int getWidth();
    // Return the height
    int getHeight();
    // Return visible stuff (invisible stuff is shown with character *)
    char get(int row, int column);
    // Flip this row/column
    void flip(int row, int column, int& iteration);
    // Is the game over?
    bool gameOver();
	
private:
    // Is the row/column valid?
    bool valid(int row, int column);
    // Did the cell at current row/column match the cell at the last row/column 
    bool matched(int row, int column);
    // Fields (member data)
    // Randomly generated grid. This has pairs of characters in it
    char ** grid;
    // What is visible to the user?
    char ** visible;
    // What's the width?
    int width;
    // What's the height?
    int height;
    // What'd we flip last?
    int lastRow;
    int lastColumn;
	int llR;
	int llC;
    State state;
};

// Show (output) the state of the model
class View {
public:
    // Print out the visible stuff in the grid
    void show(Model * model);
};

// Handle input
class Controller {
public:
    Controller() {
        model = new Model(8,8);
        view = new View;
    }
    ~Controller() {
        delete model;
        delete view;
    }
    // Event loop
    void loop();
private:
    Model * model;
    View * view;
};

// Constructor initializes the object
Model::Model(int w, int h) {
    width = w;
    height = h;
    lastRow = -1;
    lastColumn = -1;
    state = FIRST;
    grid = new char*[height];
    visible = new char*[height];
    // For every row, create the array for that row
    for (int i = 0; i < height; i++) {
        grid[i] = new char[width];
        visible[i] = new char[width];
    }
    srand(time(0));
	char letter = 'A';
	int iteration=1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
           visible[i][j] = '*';
            // Everything's invisible at first
			grid[i][j] = letter;
			if (iteration % 2 == 0){
				
				letter++;
			}
			iteration++;
			if (iteration == 53){
				letter = 'A';
			}
        }
    }
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::swap(grid[i][j], grid[rand() % (height)][rand() % (width)]);
		}
	}

		
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
    for (int i = 0; i < height; i++) {
        delete grid[i];
        delete visible[i];
    }
    delete grid;
    delete visible;
}
// That is, is the row within the height, and is the column within the width?
// Return whether it is or isn't.
bool Model::valid(int row, int column) {
	if (row >= 0 && row <= height && column >= 0 && column <= width)
		return true;
	else
		return false;
}
bool Model::matched(int row, int column) {
    return true;
}
// TODO: Flip a cell
void Model::flip(int row, int column, int& iteration) {
	// If the row and column are not valid, break out and don't do anything
	if (!valid(row, column)) {return; }
	if (visible[row][column] == grid[row][column]) { iteration--; return; }
	visible[row][column] = grid[row][column];
	
	if (iteration == 1)
	{
		lastRow = row;
		lastColumn = column;
		return;
	}
	

	if (iteration == 2)
	{
			llR = lastRow;
			llC = lastColumn;
			lastRow = row;
			lastColumn = column;
		
	}
	if (iteration == 3)
	{
		if (visible[lastRow][lastColumn] == visible[llR][llC])
		{
			iteration = 1;
		}
		
		else{
			visible[lastRow][lastColumn] = '*';
			visible[llR][llC] = '*';
			iteration = 1;
			
		}
		llR = lastRow;
		llC = lastColumn;
		lastRow = row;
		lastColumn = column;
	}
	return;
}
// TODO: If everything is visible, then it's game over
bool Model::gameOver() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (visible[i][j] == '*'){
				return false;
			}
		}
	}
	return true;
}
int Model::getWidth() {
    return width;
}
int Model::getHeight() {
    return height;
}
char Model::get(int row, int col) {
    return visible[row][col];
}
// Show the model, one cell at a time
void View::show(Model * model) {
    for (int j = 0; j < model->getWidth(); j++) {
        cout << "\t" << j;
    }
    cout << endl;
    for (int i = 0; i < model->getHeight(); i++) {
        cout << i;
        for (int j = 0; j < model->getWidth(); j++) {
            cout << "\t" << model->get(i, j);
        }
        cout << endl;
    }
}

// Show the board
// Read in coordinates
// Until we're done
void Controller::loop() {
	int row, col;
	int iteration = 1;
    while (!model->gameOver()) {
		view->show(model);
        cout << "Enter row:    ";
        cin >> row;
        cout << "Enter column: ";
        cin >> col;
        model->flip(row, col, iteration);
		iteration++;
    }
    cout << "Hooray, you win!" << endl;
}

int main() {
    Controller c;
    c.loop();
}
