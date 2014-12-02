#include <stdio.h>
#include <nark/util/linebuf.hpp>

int main() {
	nark::LineBuf line;
	while (line.getline(stdin) > 0) {
		line.chomp();
		int32_t len = line.n;
		fwrite(&len, 4, 1, stdout);
		fwrite(line.p, 1, line.n, stdout);
	}
	return 0;
}
