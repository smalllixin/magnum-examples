#ifndef Magnum_Examples_ColorCorrectionShader_h
#define Magnum_Examples_ColorCorrectionShader_h
/*
    Copyright © 2010, 2011, 2012 Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Magnum.

    Magnum is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Magnum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

#include <Math/Matrix3.h>
#include "AbstractShaderProgram.h"

namespace Magnum { namespace Examples {

/*
Fragment data:
0 - Original color
1 - Grayscale
2 - Color corrected
*/
class ColorCorrectionShader: public AbstractShaderProgram {
    public:
        typedef Attribute<0, Point2D> Position;

        static const GLint TextureLayer = 0;
        static const GLint ColorCorrectionTextureLayer = 1;

        ColorCorrectionShader();

        inline void setMatrixUniform(const Matrix3& matrix) {
            setUniform(matrixUniform, matrix);
        }

    private:
        GLint matrixUniform;
};

}}

#endif
