@ r1 disable optional_qualifier exists @
identifier tile;
@@
- Tile *tile;
++ const Tile *tile;
  ...
  tile = GetTile(...)
@ r2 disable optional_qualifier exists @
identifier tile;
@@
- Tile *tile
++ const Tile *tile
  = GetTile(...);
@ decls disable optional_qualifier @
identifier tile;
@@
(
    Tile *tile;
|
    Tile *tile = ...;
)
@ mutated depends on decls exists @
identifier decls.tile;
assignment operator op;
identifier f;
@@
(
  tile->f op ...;
|
  f(<+... tile ...+>)
)
@ notmutated depends on decls && !mutated disable optional_qualifier @
identifier decls.tile;
@@
(
- Tile *tile;
++ const Tile *tile;
|
- Tile *tile
++ const Tile *tile
  = ...;
)
