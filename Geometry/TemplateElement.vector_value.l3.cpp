/**
 * @file   TemplateElement.vector_value.l3.cpp
 * @author Robert Lie, Crazyfish
 * @date   Sat Mar 21 15:06:32 2020
 * 
 * @brief  
 * 
 * 
 */

#include "TemplateElement.templates.h"

AFEPACK_OPEN_NAMESPACE

#define vector_length 3
#define value_type nVector<vector_length,double>
#define DIM 1
	template class ShapeFunction<value_type,DIM>;

#define TDIM 1
	template class BasisFunction<value_type,DIM,TDIM>;
	template class BasisFunctionAdmin<value_type,DIM,TDIM>;
	template class TemplateElement<value_type,DIM,TDIM>;


#undef TDIM
#undef DIM

#define DIM 2
	template class ShapeFunction<value_type,DIM>;

#define TDIM 1
	template class BasisFunction<value_type,DIM,TDIM>;
	template class BasisFunctionAdmin<value_type,DIM,TDIM>;
	template class TemplateElement<value_type,DIM,TDIM>;


#undef TDIM
#define TDIM 2
	template class BasisFunction<value_type,DIM,TDIM>;
	template class BasisFunctionAdmin<value_type,DIM,TDIM>;
	template class TemplateElement<value_type,DIM,TDIM>;


#undef TDIM
#undef DIM

#define DIM 3
	template class ShapeFunction<value_type,DIM>;

#define TDIM 1
	template class BasisFunction<value_type,DIM,TDIM>;
	template class BasisFunctionAdmin<value_type,DIM,TDIM>;
	template class TemplateElement<value_type,DIM,TDIM>;


#undef TDIM
#define TDIM 2
	template class BasisFunction<value_type,DIM,TDIM>;
	template class BasisFunctionAdmin<value_type,DIM,TDIM>;
	template class TemplateElement<value_type,DIM,TDIM>;


#undef TDIM
#define TDIM 3
	template class BasisFunction<value_type,DIM,TDIM>;
	template class BasisFunctionAdmin<value_type,DIM,TDIM>;
	template class TemplateElement<value_type,DIM,TDIM>;


#undef TDIM
#undef DIM
#undef value_type
#undef vector_length

AFEPACK_CLOSE_NAMESPACE

/**
 * end of file
 * 
 */
