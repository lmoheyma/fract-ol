//Mandelbar
// fractal->tempx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
// 			+ fractal->cx;
// fractal->zy = -2.0 * fractal->zx * fractal->zy + fractal->cy;
// fractal->zx = fractal->tempx;


//Perpendicular Burning Ship
// fractal->tempx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
// 			+ fractal->cx;
// fractal->zy = -2.0 * fractal->zx * fabs(fractal->zy) + fractal->cy;
// fractal->zx = fractal->tempx;


//faire une fonction pour afficher les fractals available
//passer en argument les parametres de Julia
//leaks ?
//touches pour augmenter ou diminuer le nb d'iterations
    //if iter > 100
    //     -= 100
    // else if (iter < 1000)
    //     += 50;
