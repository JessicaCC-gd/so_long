# so_long
Project from 42 school

## HOW TO USE
#### 1º - Clone the repository
```bash
git clone git@github.com:LeRandomJess/so_long.git
```
#### 2º - Enter the project folder so_long or so_long_bonus and run `make`
> **Important:** To run the program, you need to download the MiniLibX, name it "mlx" and place the folder inside the project folder.
```bash
cd so_long/so_long or cd so_long_bonus
make
```

#### 3º - Run the game with a map of your choice
```bash
./so_long /maps/[map.ber]
./so_long_bonus /maps/[map_bonus.ber]
```

#### MAKEFILE RULES

`make` - Compile so_long files.

`make all`  - Compile so_long files.

`make clean`  - Delete all .o (object files) files.

`make fclean`  - Delete all .o (object files) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.
