Files in this directory

- `digit.sh` - Helper script to generate the `unsigned char NUM [] = {...` code.
- `number.xcf` - Gimp project file I used to generate each digit.

Example usage of `digit.sh`

    ./digit.sh 1

This will use `g++` to compile a program that includes the `1.c` saved by gimp, and output the result as the last line of the program.

To generate any of the `.c` files, choose `Export` in Gimp, and export to `C Source file *.c`. This should generate something like the following:

	trigen@zenbook ~/p/n/clock_numbers (master)> head -n 10 0.c
	/* GIMP RGBA C-Source image dump (0.c) */

	static const struct {
	  guint  	 width;
	  guint  	 height;
	  guint  	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
	  guint8 	 pixel_data[64 * 127 * 4 + 1];
	} gimp_image = {
	  64, 127, 4,
	  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"

As mentioned before `./digit.sh 0` will compile and run a simple c++ program that takes the gimp generated stuff and preps it for our clock.

