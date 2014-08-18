#include <stdint.h>
#include <string.h>
#include <stdlib.h>


int osmo_macaddr_parse(uint8_t *out, const char *in)
{
	/* 00:00:00:00:00:00 */
	char tmp[18];
	char *tok;
	unsigned int i = 0;

	if (strlen(in) < 17)
		return -1;

	strncpy(tmp, in, sizeof(tmp)-1);
	tmp[sizeof(tmp)-1] = '\0';

	for (tok = strtok(tmp, ":"); tok && (i < 6); tok = strtok(NULL, ":")) {
		unsigned long ul = strtoul(tok, NULL, 16);
		out[i++] = ul & 0xff;
	}

	return 0;
}
