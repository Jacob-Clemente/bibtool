/*** cboolean.c*****************************************************************
** 
** This file is part of BibTool.
** It is distributed under the GNU General Public License.
** See the file COPYING for details.
** 
** (c) 2016 Gerd Neugebauer
** 
** Net: gene@gerd-neugebauer.de
** 
******************************************************************************/

#include <bibtool/general.h>
#include <bibtool/symbols.h>
#include <bibtool/error.h>
#include <bibtool/type.h>
#include <bibtool/sbuffer.h>
#include "binding.h"
#include "lcore.h"

/*****************************************************************************/
/* Internal Programs                                                         */
/*===========================================================================*/

#ifdef __STDC__
#define _ARG(A) A
#else
#define _ARG(A) ()
#endif

/*****************************************************************************/
/* External Programs                                                         */
/*===========================================================================*/


/*---------------------------------------------------------------------------*/


Binding cb_binding = NULL;		   	   /*                        */

#define Bind(NAME,GET)  bind(cb_binding, symdef(symbol((String)NAME),     \
						0, 0, GET, NULL));

/*-----------------------------------------------------------------------------
** Function:	m_as_string()
** Type:	Term
** Purpose:	
**		
** Arguments:
**	binding	
**	boolean	
**	args	
** Returns:	
**___________________________________________________			     */
static Term m_as_string(binding, boolean, args)	   /*                        */
  Binding binding;				   /*                        */
  Term boolean;					   /*                        */
  Term args;					   /*                        */
{						   /*                        */
  no_args(args, "as.string");  		   	   /*                        */
  return eval_str(binding, boolean);		   /*                        */
}						   /*------------------------*/

/*-----------------------------------------------------------------------------
** Function:	m_as_number()
** Type:	Term
** Purpose:	
**		
** Arguments:
**	binding	
**	boolean	
**	args	
** Returns:	
**___________________________________________________			     */
static Term m_as_number(binding, boolean, args)	   /*                        */
  Binding binding;				   /*                        */
  Term boolean;					   /*                        */
  Term args;					   /*                        */
{						   /*                        */
  no_args(args, "as.number");  		   	   /*                        */
 						   /*                        */
  return eval_num(binding, boolean);		   /*                        */
}						   /*------------------------*/

/*-----------------------------------------------------------------------------
** Function:	class_boolean()
** Type:	void
** Purpose:	
**		
** Arguments:
**		
** Returns:	nothing
**___________________________________________________			     */
void class_boolean()				   /*                        */
{						   /*                        */
  cb_binding = binding(127, NULL);		   /*                        */
 						   /*                        */
  Bind("as.string", m_as_string);		   /*                        */
  Bind("as.number", m_as_number);		   /*                        */
}						   /*------------------------*/

/*---------------------------------------------------------------------------*/