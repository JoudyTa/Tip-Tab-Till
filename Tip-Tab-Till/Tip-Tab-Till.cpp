#include<bits\stdc++.h>
using namespace std;

class Pinguin {
public:Pinguin() {}

	  int x, y;
	  int num_of_moveminte = 0;
};

class State {


	int n, m;
public:
	State(int n, int m) {
		this->n = n;
		this->m = m;
	};

	char table[150][150];
	char dirction;
	int num_red_cells;
	int fun = this->num_red_cells + this->pinguin.num_of_moveminte;
	vector<State>children;
	Pinguin pinguin;
	State* parent;



	void initialisation() {

		fill((char*)table, (char*)table + sizeof(table) / sizeof(char), 'b');

	}

	void copy_with(char table[][150], char dirction, int num_red_cells, Pinguin cu_pingiun, State* cu_parent) {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				this->table[i][j] = table[i][j];
			}
		this->num_red_cells = num_red_cells;
		this->dirction = dirction;
		this->pinguin.x = cu_pingiun.x;
		this->pinguin.y = cu_pingiun.y;
		this->pinguin.num_of_moveminte = cu_pingiun.num_of_moveminte;
		this->parent = cu_parent;
	}

	void print() {

		for (int i = 0; i < n; i++) {
			if (i == 0)
			{
				cout << "      _______POSITION OF PINGUIN IS : (" << this->pinguin.x << "," << this->pinguin.y << ")_______      " << endl;
				cout << "           Number of Pinguin's Movment is : " << this->pinguin.num_of_moveminte << endl;
			}
			for (int j = 0; j < m; j++) {
				cout << this->table[i][j] << " ";

			}
			cout << endl;
		}

	};

	/*
	* W refers to up
	* S refers to down
	* A refers to left
	* D refers ro right
	*/

	void move(char dirction) {

		switch (dirction)
		{
		case 'w':
			up_move();
			break;
		case 's':
			down_move();
			break;
		case 'd':
			right_move();
			break;
		case 'a':
			left_move();
			break;

		}

	}

	void right_move() {

		if (((pinguin.y + 1) > (m - 1)))

			cout << "you can't move" << endl;

		else
		{
			if (table[pinguin.x][pinguin.y + 1] == 'b')

				cout << "you can't move" << endl;

			else
			{
				if (table[pinguin.x][pinguin.y + 1] == 'r')
				{
					table[pinguin.x][pinguin.y + 1] = 'w';
					num_red_cells--;
					dirction = 'd';
					pinguin.y = pinguin.y + 1;
					pinguin.num_of_moveminte = pinguin.num_of_moveminte + 1;


				}
				else
					if (table[pinguin.x][pinguin.y + 1] == 'w')
					{
						table[pinguin.x][pinguin.y + 1] = 'r';
						num_red_cells++;
						dirction = 'd';
						pinguin.y = pinguin.y + 1;
						pinguin.num_of_moveminte = pinguin.num_of_moveminte + 1;

					}
			}
		}
	}

	void left_move() {

		if (((pinguin.y - 1) < 0))

			cout << "you can't move" << endl;

		else
		{
			if (table[pinguin.x][pinguin.y - 1] == 'b')

				cout << "you can't move" << endl;

			else
			{
				if (table[pinguin.x][pinguin.y - 1] == 'r')
				{
					table[pinguin.x][pinguin.y - 1] = 'w';
					num_red_cells--;
					dirction = 'a';
					pinguin.y = pinguin.y - 1;
					pinguin.num_of_moveminte = pinguin.num_of_moveminte + 1;

				}
				else
					if (table[pinguin.x][pinguin.y - 1] == 'w')
					{
						table[pinguin.x][pinguin.y - 1] = 'r';
						num_red_cells++;
						dirction = 'a';
						pinguin.y = pinguin.y - 1;
						pinguin.num_of_moveminte = pinguin.num_of_moveminte + 1;

					}
			}
		}
	}

	void up_move() {

		if (((pinguin.x - 1) < 0))

			cout << "you can't move" << endl;

		else
		{
			if (table[pinguin.x - 1][pinguin.y] == 'b')

				cout << "you can't move" << endl;

			else
			{
				if (table[pinguin.x - 1][pinguin.y] == 'r')
				{
					table[pinguin.x - 1][pinguin.y] = 'w';
					num_red_cells--;
					pinguin.x = pinguin.x - 1;
					pinguin.num_of_moveminte = pinguin.num_of_moveminte + 1;
					dirction = 'w';


				}

				else
				{
					if (table[pinguin.x - 1][pinguin.y] == 'w')
					{
						table[pinguin.x - 1][pinguin.y] = 'r';
						num_red_cells++;
						pinguin.x = pinguin.x - 1;
						pinguin.num_of_moveminte = pinguin.num_of_moveminte + 1;
						dirction = 'w';

					}
				}
			}
		}
	}

	void down_move() {

		if (((pinguin.x + 1) > (n - 1)))

			cout << "you can't move" << endl;

		else
		{
			if (table[pinguin.x + 1][pinguin.y] == 'b')

				cout << "you can't move" << endl;

			else
			{
				if (table[pinguin.x + 1][pinguin.y] == 'r')
				{
					table[pinguin.x + 1][pinguin.y] = 'w';
					num_red_cells--;
					pinguin.x = pinguin.x + 1;
					pinguin.num_of_moveminte = pinguin.num_of_moveminte + 1;
					dirction = 's';


				}

				else
				{
					if (table[pinguin.x + 1][pinguin.y] == 'w')
					{
						table[pinguin.x + 1][pinguin.y] = 'r';
						num_red_cells++;
						pinguin.x = pinguin.x + 1;
						pinguin.num_of_moveminte = pinguin.num_of_moveminte + 1;
						dirction = 's';

					}
				}
			}
		}
	}

	bool goal() {
		if (num_red_cells == 0)
			return 1;
		else
			return 0;
	}

	void child(char ch_table[][150], char ch_dirction, int ch_num_red_cells, Pinguin ch_pinguin, State* ch_parent) {

		/* ch for testing without overload on basic table*/
		char all_dirctions[4] = { 'w','s','a','d' };


		State* ch2 = new State(n, m);
		for (int j = 0; j < 4; j++) {
			bool pass = 0;
			ch2->copy_with(ch_table, ch_dirction, ch_num_red_cells, ch_pinguin, ch_parent);
			pass = ch2->find_dirction(all_dirctions[j]);
			if (pass == 1)
			{
				ch2->fun = ch2->num_red_cells + ch2->pinguin.num_of_moveminte;
				children.push_back(*ch2);


			}


		}

	}

	bool find_dirction(char dir)
	{
		if (dir == 'w')
		{
			if (!((pinguin.x - 1) < 0))
				if (table[pinguin.x - 1][pinguin.y] == 'r' || table[pinguin.x - 1][pinguin.y] == 'w')

				{
					move(dir);
					return 1;

				}
		}
		else
			if (dir == 's')
			{
				if (!((pinguin.x + 1) > (n - 1)))
					if (table[pinguin.x + 1][pinguin.y] == 'r' || table[pinguin.x + 1][pinguin.y] == 'w')
					{
						move(dir);
						return 1;

					}
			}
			else
				if (dir == 'a')
				{
					if (!((pinguin.y - 1) < 0))
						if (table[pinguin.x][pinguin.y - 1] == 'r' || table[pinguin.x][pinguin.y - 1] == 'w')
						{
							move(dir);
							return 1;

						}
				}
				else
					if (dir == 'd')
					{
						if (!((pinguin.y + 1) > (m - 1)))
							if (table[pinguin.x][pinguin.y + 1] == 'r' || table[pinguin.x][pinguin.y + 1] == 'w')
							{
								move(dir);
								return 1;
							}
					}
		return 0;

	}

	void  children_print() {

		child(this->table, this->dirction, this->num_red_cells, this->pinguin, this->parent);
		for (int i = 0; i < children.size(); i++)
		{
			cout << "Dirction_key is : " << children[i].dirction << endl;
			cout << "Child :" << i + 1 << " is : " << endl;
			children[i].print();


		}
	}

	void print_solution() {
		State* mid_state = new State(n, m);
		mid_state->copy_with(this->table, this->dirction, this->num_red_cells, this->pinguin, this->parent);
		int num_of_steps = mid_state->pinguin.num_of_moveminte;
		stack<State*>sk;
		for (int i = 0; i < num_of_steps; i++) {

			sk.push(mid_state);
			mid_state = mid_state->parent;

		}
		cout << "            _______Path of solution is : _______            " << endl;
		for (int k = 0; k < num_of_steps; k++) {
			cout << "Move Key : " << sk.top()->dirction << endl;
			sk.top()->print();
			sk.pop();
		}
	}

	bool equal(State* state) {
		bool eq = 0;
		if (this->n == state->n)
			if (this->m == state->m)
				if (this->pinguin.x == state->pinguin.x)
					if (this->pinguin.y == state->pinguin.y)
						for (int i = 0; i < n; i++)
						{
							for (int j = 0; j < m; j++)
								if (this->table[i][j] == state->table[i][j])
								{
									eq = 1;
								}
								else {
									eq = 0;
									break;
								}
							if (eq == 0)
								break;
						}

		return eq;

	}
	int i = 0;
	bool isvisited(State ste, vector<State> visited) {

		for (; i < visited.size(); i++) {

			if (visited[i].equal(&ste))
			{
				return 1;
			}
		}
		return 0;

	}

	bool isvisitedqueue(State ste, queue<State> qu) {
		queue<State>queue = qu;

		for (int i = 0; i < queue.size(); i++) {

			if (queue.front().equal(&ste))
			{
				return 1;
			}
			else
				queue.pop();
		}
		return 0;

	}

	void DFS(vector<State> visited, stack<State>stack) {
		State* in_state = new State(n, m);

		in_state->copy_with(this->table, this->dirction, this->num_red_cells, this->pinguin, this->parent);

		stack.push(*in_state);
		visited.pop_back();
		while (!stack.empty()) {

			if (!stack.top().goal())
			{
				if (!stack.top().isvisited(stack.top(), visited))
				{
					visited.push_back(stack.top());
					State* ch = new State(n, m);

					ch->copy_with(stack.top().table, stack.top().dirction, stack.top().num_red_cells, stack.top().pinguin, stack.top().parent);
					ch->child(stack.top().table, stack.top().dirction, stack.top().num_red_cells, stack.top().pinguin, ch);
					//  stack.top().print();
					stack.pop();
					for (int i = 0; i < ch->children.size(); i++)
					{
						stack.push(ch->children[i]);
					}
				}
				else
				{

					stack.pop();
				}

			}
			else
			{
				stack.top().print_solution();
				cout << "Number Visited States is : " << visited.size() << endl;
				break;
			}

		}
		return;

	}

	void BFS(vector<State>visited, queue<State>queue) {
		State* in_state = new State(n, m);
		in_state->copy_with(this->table, this->dirction, this->num_red_cells, this->pinguin, this->parent);

		queue.push(*in_state);
		visited.pop_back();
		while (!queue.empty()) {

			if (!queue.front().goal())
			{
				if (!queue.front().isvisited(queue.front(), visited))

				{
					visited.push_back(queue.front());
					State* ch = new State(n, m);
					ch->copy_with(queue.front().table, queue.front().dirction, queue.front().num_red_cells, queue.front().pinguin, queue.front().parent);
					ch->child(queue.front().table, queue.front().dirction, queue.front().num_red_cells, queue.front().pinguin, ch);
					for (int i = 0; i < ch->children.size(); i++)
					{
						if (!ch->children[i].isvisitedqueue(ch->children[i], queue))
							queue.push(ch->children[i]);
					}
				}

			}
			else
			{
				queue.front().print_solution();
				cout << "Number Visited States is : " << visited.size() << endl;
				//break;
				return;
			}

			queue.pop();
		}


	}

	void UCS(vector<State>visited) {

		priority_queue<State, vector<State>, CompareForUSC> queue;
		State* in_state = new State(n, m);
		in_state->copy_with(this->table, this->dirction, this->num_red_cells, this->pinguin, this->parent);

		queue.push(*in_state);
		visited.pop_back();
		while (!queue.empty()) {
			State te = queue.top();
			queue.pop();

			if (!te.goal())
			{
				if (!te.isvisited(te, visited))

				{
					visited.push_back(te);
					State* ch = new State(n, m);
					ch->copy_with(te.table, te.dirction, te.num_red_cells, te.pinguin, te.parent);
					ch->child(te.table, te.dirction, te.num_red_cells, te.pinguin, ch);

					for (int i = 0; i < ch->children.size(); i++)
					{
						if (!ch->children[i].isvisitedPriorityqueue_UCS(ch->children[i], queue))
							queue.push(ch->children[i]);
					}

				}

			}
			else
			{
				te.print_solution();
				cout << "Number Visited States is : " << visited.size() << endl;
				//break;
				return;
			}

		}

	}

	void ASTAR(vector<State> visited) {
		priority_queue<State, vector<State>, CompareForAStare> queue;
		State* in_state = new State(n, m);
		in_state->copy_with(this->table, this->dirction, this->num_red_cells, this->pinguin, this->parent);

		queue.push(*in_state);
		visited.pop_back();
		while (!queue.empty()) {
			State te = queue.top();
			queue.pop();

			if (!te.goal())
			{

				if (!te.isvisited(te, visited))
				{
					visited.push_back(te);
				}
				else
					if (((visited[i].num_red_cells + visited[i].pinguin.num_of_moveminte) >
						(te.num_red_cells + te.pinguin.num_of_moveminte)))
					{
						visited[i].copy_with(te.table, te.dirction, te.num_red_cells, te.pinguin, te.parent);
					}
					else
						continue;

				State* ch = new State(n, m);
				ch->copy_with(te.table, te.dirction, te.num_red_cells, te.pinguin, te.parent);
				ch->child(te.table, te.dirction, te.num_red_cells, te.pinguin, ch);

				for (int i = 0; i < ch->children.size(); i++)
				{
					if (!ch->children[i].isvisitedPriorityqueue_ASTARE(ch->children[i], queue))
						queue.push(ch->children[i]);
				}

			}
			else
			{
				te.print_solution();
				cout << "Number Visited States is : " << visited.size() << endl;
				//break;
				return;
			}

		}

	}

	void MiniMax(vector<State> visited) {

	

	}

	struct CompareForUSC {
		bool operator()(State const& s1, State const& s2)
		{
			return s1.pinguin.num_of_moveminte > s2.pinguin.num_of_moveminte;
		}
	};

	struct CompareForAStare {
		bool operator()(State const& s1, State const& s2)
		{
			return (s1.pinguin.num_of_moveminte + s1.num_red_cells) > (s2.pinguin.num_of_moveminte + s2.num_red_cells);
		}
	};

	bool isvisitedPriorityqueue_UCS(State ste, priority_queue<State, vector<State>, CompareForUSC> qu) {
		priority_queue<State, vector<State>, CompareForUSC> queue = qu;

		for (int i = 0; i < queue.size(); i++) {
			State te = queue.top();
			if (te.equal(&ste))
			{
				return 1;
			}
			else
				queue.pop();
		}
		return 0;

	}

	bool isvisitedPriorityqueue_ASTARE(State ste, priority_queue<State, vector<State>, CompareForAStare> qu) {
		priority_queue<State, vector<State>, CompareForAStare> queue = qu;

		for (int i = 0; i < queue.size(); i++) {
			State te = queue.top();
			if (te.equal(&ste))
			{
				return 1;
			}
			else
				queue.pop();
		}
		return 0;

	}

};



int main() {
	/*
	* N refers to rows
	* M refers to colum
	*/
	int n, m, num_red_cells, num_white_cells;
	cout << "Enter volum of table n&m : " << endl;
	cin >> n >> m;
	Pinguin* pinguin = new Pinguin;
	State* state = new State(n, m);
	state->initialisation();

	cout << "Enter number of red and white cells : " << endl;
	cin >> num_red_cells >> num_white_cells;

	while ((num_red_cells > (n * m)) ||
		(num_white_cells > (n * m)) ||
		((num_red_cells + num_white_cells) > (n * m)))
	{

		cout << "Unvailable..." << endl;
		cout << "Enter number of red and white cells : " << endl;
		cin >> num_red_cells >> num_white_cells;
	}

	state->num_red_cells = num_red_cells;


	if (num_red_cells != 0)
		cout << "Enter positions of red cells : " << endl;
	for (int i = 0; i < num_red_cells; i++) {
		int p_x, p_y;
		cin >> p_x >> p_y;
		state->table[p_x][p_y] = 'r';

	}

	if (num_white_cells != 0)
		cout << "Enter positions of white cells : " << endl;
	for (int i = 0; i < num_white_cells; i++) {
		int p_x, p_y;
		cin >> p_x >> p_y;
		state->table[p_x][p_y] = 'w';

	}

	cout << "Enter positions of Pinguin : " << endl;
	cin >> pinguin->x >> pinguin->y;
	state->pinguin.x = pinguin->x;
	state->pinguin.y = pinguin->y;
	/* P refers to parking (first state) */
	state->dirction = 'p';

	State* mid_state = new State(n, m);
	mid_state->copy_with(state->table, state->dirction, num_red_cells, state->pinguin, state);
	state->print();


	vector<State>visited;
	stack<State>stack;
	queue<State>queue;
	visited.push_back(*state);

	cout << "\n     Enter \n \'D\' for DFS \n \'B\' for BFS \n \'U\' for UCS \n \'A\' for A_STAR \n \'M\' for MiniMax \n \'S\' to play : ";
	char play;
	cin >> play;
	cout << endl;

	switch (play)
	{
	case 'D':
		mid_state->DFS(visited, stack);
		break;
	case 'B':
		mid_state->BFS(visited, queue);
		break;
	case 'U':
		mid_state->UCS(visited);
		break;
	case 'A':
		mid_state->ASTAR(visited);
		break;
	case 'M':
		mid_state->MiniMax(visited);
		break;
	case 'S':
		while (mid_state->num_red_cells != 0)
		{
			State* current_state = new State(n, m);

			char diriction;
			cout << "Enter diriction : " << endl;
			cin >> diriction;

			current_state->copy_with(mid_state->table, diriction, mid_state->num_red_cells, mid_state->pinguin, mid_state->parent);
			current_state->move(diriction);
			current_state->print();
			mid_state->copy_with(current_state->table, diriction, current_state->num_red_cells, current_state->pinguin, current_state);

		}
		mid_state->print_solution();
		break;
	}




}
