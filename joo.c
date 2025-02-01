#include <pwd.h>
#include <sys/types.h>
#include <err.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void __attribute__((noreturn)) aja(char** argv) {
	if (setuid(0) < 0)
		err(1, "setuid epäonnistui");
	if (setgid(0) < 0)
		err(1, "setgid epäonnistui");
	execvp(argv[0], argv);
	err(1, "%s", argv[0]);
}

/* Jos sudo tai doas on uudelleenohjattu täksi ohjelmaksi,
   on tarpeen poistaa kyseisen ohjelman argumentit. */
char** poista_argumentit(char** argv) {
	while (*++argv)
		if (argv[0][0] != '-')
			return argv;
	errx(1, "Pelkkiä argumentteja");
}

int etsi(const char* nimi) {
	char a[128];
	const char* tied = "/etc/joo.conf";
	FILE *f = fopen(tied, "r");
	if (!f) err(1, "fopen %s", tied);
	while (1)
		if (fscanf(f, "%127s", a) != 1)
			return fclose(f), 1;
		else if (!strcmp(a, nimi))
			return fclose(f), 0;
}

int main(int argc, char** argv) {
	int ruid = getuid();

	if (argc < 2)  return 0;
	if (geteuid()) errx(1, "Asetettakoon SUID-bitti joo:hon (chmod u+s).");
	if (ruid == 0) aja(&argv[1]);

	struct passwd* pw = getpwuid(ruid);
	if (!pw)
		err(1, "getpwuid epäonnistui");

	if (etsi(pw->pw_name))
		errx(1, "Hähää! Eipäs ole oikeuksia käyttäjällä %s. (/etc/joo.conf)", pw->pw_name);

	aja(poista_argumentit(argv));
}
