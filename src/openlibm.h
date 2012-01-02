/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/*
 * from: @(#)fdlibm.h 5.1 93/09/24
 * $FreeBSD: src/lib/msun/src/openlibm.h,v 1.82 2011/11/12 19:55:48 theraven Exp $
 */

#ifndef _OPENLIBM_H_
#define	_OPENLIBM_H_

#include <math.h>
#include <sys/cdefs.h>
#include <sys/_types.h>
#include <machine/_limits.h>

//VBS begin
#define __ISO_C_VISIBLE 1999
//VBS end


/*
 * Most of these functions depend on the rounding mode and have the side
 * effect of raising floating-point exceptions, so they are not declared
 * as __pure2.  In C99, FENV_ACCESS affects the purity of these functions.
 */
__BEGIN_DECLS
/*
 * ANSI/POSIX
 */
int	__fpclassifyd(double) __pure2;
int	__fpclassifyf(float) __pure2;
int	__fpclassifyl(long double) __pure2;
int	__isfinitef(float) __pure2;
int	__isfinite(double) __pure2;
int	__isfinitel(long double) __pure2;
int	__isinff(float) __pure2;
int	__isinfl(long double) __pure2;
int	__isnanf(float) __pure2;
int	__isnanl(long double) __pure2;
int	__isnormalf(float) __pure2;
int	__isnormal(double) __pure2;
int	__isnormall(long double) __pure2;
int	__signbit(double) __pure2;
int	__signbitf(float) __pure2;
int	__signbitl(long double) __pure2;

double	acos(double);
double	asin(double);
double	atan(double);
double	atan2(double, double);
double	cos(double);
double	sin(double);
double	tan(double);

double	cosh(double);
double	sinh(double);
double	tanh(double);

double	exp(double);
double	frexp(double, int *);	/* fundamentally !__pure2 */
double	ldexp(double, int);
double	log(double);
double	log10(double);
double	modf(double, double *);	/* fundamentally !__pure2 */

double	pow(double, double);
double	sqrt(double);

double	ceil(double);
double	fabs(double) __pure2;
double	floor(double);
double	fmod(double, double);

/*
 * These functions are not in C90.
 */
#if __BSD_VISIBLE || __ISO_C_VISIBLE >= 1999 || __XSI_VISIBLE
double	acosh(double);
double	asinh(double);
double	atanh(double);
double	cbrt(double);
double	erf(double);
double	erfc(double);
double	exp2(double);
double	expm1(double);
double	fma(double, double, double);
double	hypot(double, double);
int	ilogb(double) __pure2;
int	(isinf)(double) __pure2;
int	(isnan)(double) __pure2;
double	lgamma(double);
long long llrint(double);
long long llround(double);
double	log1p(double);
double	log2(double);
double	logb(double);
long	lrint(double);
long	lround(double);
double	nan(const char *) __pure2;
double	nextafter(double, double);
double	remainder(double, double);
double	remquo(double, double, int *);
double	rint(double);
#endif /* __BSD_VISIBLE || __ISO_C_VISIBLE >= 1999 || __XSI_VISIBLE */

#if __BSD_VISIBLE || __XSI_VISIBLE
double	j0(double);
double	j1(double);
double	jn(int, double);
double	y0(double);
double	y1(double);
double	yn(int, double);

#if __XSI_VISIBLE <= 500 || __BSD_VISIBLE
double	gamma(double);
#endif

#if __XSI_VISIBLE <= 600 || __BSD_VISIBLE
double	scalb(double, double);
#endif
#endif /* __BSD_VISIBLE || __XSI_VISIBLE */

#if __BSD_VISIBLE || __ISO_C_VISIBLE >= 1999
double	copysign(double, double) __pure2;
double	fdim(double, double);
double	fmax(double, double) __pure2;
double	fmin(double, double) __pure2;
double	nearbyint(double);
double	round(double);
double	scalbln(double, long);
double	scalbn(double, int);
double	tgamma(double);
double	trunc(double);
#endif

/*
 * BSD math library entry points
 */
#if __BSD_VISIBLE
double	drem(double, double);
int	finite(double) __pure2;
int	isnanf(float) __pure2;

/*
 * Reentrant version of gamma & lgamma; passes signgam back by reference
 * as the second argument; user must allocate space for signgam.
 */
double	gamma_r(double, int *);
double	lgamma_r(double, int *);

/*
 * IEEE Test Vector
 */
double	significand(double);
#endif /* __BSD_VISIBLE */

/* float versions of ANSI/POSIX functions */
#if __ISO_C_VISIBLE >= 1999
float	acosf(float);
float	asinf(float);
float	atanf(float);
float	atan2f(float, float);
float	cosf(float);
float	sinf(float);
float	tanf(float);

float	coshf(float);
float	sinhf(float);
float	tanhf(float);

float	exp2f(float);
float	expf(float);
float	expm1f(float);
float	frexpf(float, int *);	/* fundamentally !__pure2 */
int	ilogbf(float) __pure2;
float	ldexpf(float, int);
float	log10f(float);
float	log1pf(float);
float	log2f(float);
float	logf(float);
float	modff(float, float *);	/* fundamentally !__pure2 */

float	powf(float, float);
float	sqrtf(float);

float	ceilf(float);
float	fabsf(float) __pure2;
float	floorf(float);
float	fmodf(float, float);
float	roundf(float);

float	erff(float);
float	erfcf(float);
float	hypotf(float, float);
float	lgammaf(float);
float	tgammaf(float);

float	acoshf(float);
float	asinhf(float);
float	atanhf(float);
float	cbrtf(float);
float	logbf(float);
float	copysignf(float, float) __pure2;
long long llrintf(float);
long long llroundf(float);
long	lrintf(float);
long	lroundf(float);
float	nanf(const char *) __pure2;
float	nearbyintf(float);
float	nextafterf(float, float);
float	remainderf(float, float);
float	remquof(float, float, int *);
float	rintf(float);
float	scalblnf(float, long);
float	scalbnf(float, int);
float	truncf(float);

float	fdimf(float, float);
float	fmaf(float, float, float);
float	fmaxf(float, float) __pure2;
float	fminf(float, float) __pure2;
#endif

/*
 * float versions of BSD math library entry points
 */
#if __BSD_VISIBLE
float	dremf(float, float);
int	finitef(float) __pure2;
float	gammaf(float);
float	j0f(float);
float	j1f(float);
float	jnf(int, float);
float	scalbf(float, float);
float	y0f(float);
float	y1f(float);
float	ynf(int, float);

/*
 * Float versions of reentrant version of gamma & lgamma; passes
 * signgam back by reference as the second argument; user must
 * allocate space for signgam.
 */
float	gammaf_r(float, int *);
float	lgammaf_r(float, int *);

/*
 * float version of IEEE Test Vector
 */
float	significandf(float);
#endif	/* __BSD_VISIBLE */

/*
 * long double versions of ISO/POSIX math functions
 */
#if __ISO_C_VISIBLE >= 1999
#if _DECLARE_C99_LDBL_MATH
long double	acoshl(long double);
#endif
long double	acosl(long double);
#if _DECLARE_C99_LDBL_MATH
long double	asinhl(long double);
#endif
long double	asinl(long double);
long double	atan2l(long double, long double);
#if _DECLARE_C99_LDBL_MATH
long double	atanhl(long double);
#endif
long double	atanl(long double);
long double	cbrtl(long double);
long double	ceill(long double);
long double	copysignl(long double, long double) __pure2;
#if _DECLARE_C99_LDBL_MATH
long double	coshl(long double);
#endif
long double	cosl(long double);
#if _DECLARE_C99_LDBL_MATH
long double	erfcl(long double);
long double	erfl(long double);
#endif
long double	exp2l(long double);
#if _DECLARE_C99_LDBL_MATH
long double	expl(long double);
long double	expm1l(long double);
#endif
long double	fabsl(long double) __pure2;
long double	fdiml(long double, long double);
long double	floorl(long double);
long double	fmal(long double, long double, long double);
long double	fmaxl(long double, long double) __pure2;
long double	fminl(long double, long double) __pure2;
long double	fmodl(long double, long double);
long double	frexpl(long double value, int *); /* fundamentally !__pure2 */
long double	hypotl(long double, long double);
int		ilogbl(long double) __pure2;
long double	ldexpl(long double, int);
#if _DECLARE_C99_LDBL_MATH
long double	lgammal(long double);
#endif
long long	llrintl(long double);
long long	llroundl(long double);
#if _DECLARE_C99_LDBL_MATH
long double	log10l(long double);
long double	log1pl(long double);
long double	log2l(long double);
#endif
long double	logbl(long double);
#if _DECLARE_C99_LDBL_MATH
long double	logl(long double);
#endif
long		lrintl(long double);
long		lroundl(long double);
long double	modfl(long double, long double *); /* fundamentally !__pure2 */
long double	nanl(const char *) __pure2;
long double	nearbyintl(long double);
long double	nextafterl(long double, long double);
double		nexttoward(double, long double);
float		nexttowardf(float, long double);
long double	nexttowardl(long double, long double);
#if _DECLARE_C99_LDBL_MATH
long double	powl(long double, long double);
#endif
long double	remainderl(long double, long double);
long double	remquol(long double, long double, int *);
long double	rintl(long double);
long double	roundl(long double);
long double	scalblnl(long double, long);
long double	scalbnl(long double, int);
#if _DECLARE_C99_LDBL_MATH
long double	sinhl(long double);
#endif
long double	sinl(long double);
long double	sqrtl(long double);
#if _DECLARE_C99_LDBL_MATH
long double	tanhl(long double);
#endif
long double	tanl(long double);
#if _DECLARE_C99_LDBL_MATH
long double	tgammal(long double);
#endif
long double	truncl(long double);

#endif /* __ISO_C_VISIBLE >= 1999 */
__END_DECLS

#endif /* !_OPENLIBM_H_ */
