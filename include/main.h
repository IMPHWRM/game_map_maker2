#ifndef MAIN_H
#define MAIN_H

enum prog_error
{
	nothing,
	cannot_open_save
};

enum prog_enum
{
	error,
	menu,
	editor,
	end
};

typedef struct
{
	enum prog_enum type;
	enum prog_error error;
}prog_state;

//function

prog_state editor_loop();

#endif
