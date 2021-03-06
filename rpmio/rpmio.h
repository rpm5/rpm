#ifndef	H_RPMIO
#define	H_RPMIO

/** \ingroup rpmio
 * \file rpmio/rpmio.h
 *
 * RPM I/O API (Fd_t is RPM equivalent to libc's FILE)
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <rpm/rpmtypes.h>
#include <rpm/rpmsw.h>

#ifdef __cplusplus
extern "C" {
#endif

/** \ingroup rpmio
 */
typedef const struct FDIO_s * FDIO_t;


/** \ingroup rpmio
 * \name RPMIO Interface.
 */

/** \ingroup rpmio
 * strerror(3) clone.
 */
const char * Fstrerror(FD_t fd);

/** \ingroup rpmio
 * fread(3) clone.
 */
ssize_t Fread(void * buf, size_t size, size_t nmemb, FD_t fd);

/** \ingroup rpmio
 * fwrite(3) clone.
 */
ssize_t Fwrite(const void * buf, size_t size, size_t nmemb, FD_t fd);

/** \ingroup rpmio
 * fseek(3) clone.
 */
int Fseek(FD_t fd, off_t offset, int whence);

/** \ingroup rpmio
 * ftell(3) clone.
 */
off_t Ftell(FD_t fd);

/** \ingroup rpmio
 * POSIX fallocate(3) clone.
 */
int Fallocate(FD_t fd, off_t offset, off_t len);

/** \ingroup rpmio
 * POSIX fadvise(3) clone.
 */
int Fadvise(FD_t fd, off_t offset, off_t len, int advice);

/** \ingroup rpmio
 * fdatasync(3) clone.
 */
int Fdatasync(FD_t fd);

/** \ingroup rpmio
 * fsync(3) clone.
 */
int Fsync(FD_t fd);

/** \ingroup rpmio
 * mincore(2) wrapper onto a mmaop'able fd..
 */
int Fincore(FD_t fd, int nincore);

/** \ingroup rpmio
 * fclose(3) clone.
 */
int Fclose( FD_t fd);

/** \ingroup rpmio
 */
FD_t	Fdopen(FD_t ofd, const char * fmode);

/** \ingroup rpmio
 * fopen(3) clone.
 */
FD_t	Fopen(const char * path,
			const char * fmode);

/** \ingroup rpmio
 * Event loop start/stop operations.
 * @param eio		event loop data (NULL uses global event loop)
 * @return		0 on success
 */
int	rpmeioStart(rpmeio eio);
int	rpmeioStop(rpmeio eio);


/** \ingroup rpmio
 * fflush(3) clone.
 */
int Fflush(FD_t fd);

/** \ingroup rpmio
 * ferror(3) clone.
 */
int Ferror(FD_t fd);

/** \ingroup rpmio
 * fileno(3) clone.
 */
int Fileno(FD_t fd);

/** \ingroup rpmio
 * fcntl(2) clone.
 */
int Fcntl(FD_t fd, int op, void *lip);

/** \ingroup rpmio
 * Get informative description (eg file name) from fd for diagnostic output.
 */
const char * Fdescr(FD_t fd);

/** \ingroup rpmio
 * \name RPMIO Utilities.
 */

/** \ingroup rpmio
 */
off_t	fdSize(FD_t fd);

/** \ingroup rpmio
 */
FD_t fdDup(int fdno);

/** \ingroup rpmio
 */
FD_t fdLink(FD_t fd);

/** \ingroup rpmio
 */
FD_t fdFree(FD_t fd);

/**
 */
off_t ufdCopy(FD_t sfd, FD_t tfd);

/** \ingroup rpmio
 * Identify per-desciptor I/O operation statistics.
 */
typedef enum fdOpX_e {
    FDSTAT_READ		= 0,	/*!< Read statistics index. */
    FDSTAT_WRITE	= 1,	/*!< Write statistics index. */
    FDSTAT_SEEK		= 2,	/*!< Seek statistics index. */
    FDSTAT_CLOSE	= 3,	/*!< Close statistics index */
    FDSTAT_DIGEST	= 4,	/*!< Digest statistics index. */
    FDSTAT_SYNC		= 5,	/*!< Sync statistics index. */
    FDSTAT_INCORE	= 6,	/*!< Incore statistics index. */
    FDSTAT_MAX
} fdOpX;

/** \ingroup rpmio
 *
 */
rpmop fdOp(FD_t fd, fdOpX opx);

#ifdef __cplusplus
}
#endif

#endif	/* H_RPMIO */
