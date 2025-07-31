#include "secret_handshake.h"

#include <algorithm>

namespace secret_handshake {

std::vector<std::string> commands(size_t n){
	static const std::vector<std::string> actions{"wink", "double blink", "close your eyes", "jump"};
	std::vector<std::string> cmds;
	for (size_t i = 0; i < actions.size(); i++){
		if (n & (1 << i)){
			cmds.push_back(actions[i]);
		}
	}
	if (n & (1 << 4)){
		std::reverse(cmds.begin(), cmds.end());
	}
	return cmds;
}

}  // namespace secret_handshake
