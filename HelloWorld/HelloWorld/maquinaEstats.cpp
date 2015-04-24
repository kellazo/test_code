#include <stdio.h>
#include <math.h>
#include <String.h>

enum ryu_states
{
	ST_IDLE,
	ST_WALK_FORWARD,
	
};

enum ryu_inputs
{
	IN_NOTHING,
	IN_LEFT,
	IN_RIGHT,
	IN_UP,
	IN_DOWN,
	IN_X
};
enum main_inputs_interns
{
	MAIN_INPUT_INTERN,
	JUMP_DONE,
};

ryu_inputs read_input()
{
	ryu_inputs ret = IN_NOTHING;
	switch (getchar())
	{
	case 'a':
		ret = IN_LEFT;
		break;
	case 'd':
		ret = IN_RIGHT;
		break;
	}

	return ret;
}

int main(int argc, char** argv)

{

	bool exit = false;
	ryu_states current_state = ST_IDLE;
	ryu_inputs last_input = IN_NOTHING;
	

	while (exit == false)
	{
		last_input = read_input();
		switch (current_state)
		{
		case ST_IDLE:
			printf("State: idle");

			if (last_input == IN_RIGHT)
				current_estate ST_WALK_FORWARD<

			break;
		case ST_WALK_FORWARD:
			printf("State: walk forward");
			break;

		}
	}

	return 0;

}