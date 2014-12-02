#define _SCL_SECURE_NO_WARNINGS
#include <nark/fsa/dawg_map.hpp>
#include <nark/lcast.hpp>
#include <getopt.h>
#include <malloc.h>

using namespace nark;

struct ParseKeyInt {
	void operator()(fstring line, fstring* key, int* val) {
		line.split('\t', &F);
		*key = F[0];
		*val = nark::lcast(F[1]);
	}
	valvec<fstring> F;
};

int main(int argc, char* argv[]) {
	if (argc < 4) {
		fprintf(stderr, "usage: %s text_file dawg_dfa_file mmap_value_file\n", argv[0]);
		return 3;
	}
	if (0) {
		nark::FileStream text_file(argv[1], "r");
		DAWG_Map<int> dm(DFA_Interface::load_mmap(argv[2]));
		dm.patch_values(text_file, ParseKeyInt());
		dm.save_mmap_values(argv[3]);
	} else {
		// 通常情况下，使用这种方式创建 DAWG_Map 更简洁
		// this is the short cut
		DAWG_Map<int> dm;
		dm.complete_dawg_map_mmap(argv[1], argv[2], argv[3], ParseKeyInt());
	}
	return 0;
}

