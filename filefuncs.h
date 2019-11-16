void print_files(struct dir* node);
struct dir* insert_file(struct dir* node, char x[250]);
struct dir* free_files(struct dir* node);
struct dir* remove_file(struct dir* front, char data[250]);