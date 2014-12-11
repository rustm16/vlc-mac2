/*
 * AdaptationSet.h
 *****************************************************************************
 * Copyright (C) 2010 - 2011 Klagenfurt University
 *
 * Created on: Aug 10, 2010
 * Authors: Christopher Mueller <christopher.mueller@itec.uni-klu.ac.at>
 *          Christian Timmerer  <christian.timmerer@itec.uni-klu.ac.at>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef ADAPTATIONSET_H_
#define ADAPTATIONSET_H_

#include <vector>
#include <string>
#include <map>

#include "mpd/Representation.h"
#include "mpd/CommonAttributesElements.h"
#include "mpd/ICanonicalUrl.hpp"

namespace dash
{
    namespace mpd
    {
        class SegmentInfoDefault;
        class Period;
        class SegmentTemplate;

        class AdaptationSet : public CommonAttributesElements, public ICanonicalUrl
        {
            public:
                AdaptationSet(Period *);
                virtual ~AdaptationSet();

                virtual const std::string&      getMimeType() const; /*reimpl*/
                bool                            getSubsegmentAlignmentFlag() const;
                void                            setSubsegmentAlignmentFlag( bool alignment );
                std::vector<Representation *>&  getRepresentations      ();
                const Representation*           getRepresentationById   ( const std::string &id ) const;
                const SegmentInfoDefault*       getSegmentInfoDefault() const;
                void                            setSegmentInfoDefault( const SegmentInfoDefault* seg );
                void                            setBitstreamSwitching(bool value);
                void                            setTemplates( SegmentTemplate *, SegmentTemplate * = NULL );
                std::vector<SegmentTemplate *>  getTemplates() const;
                bool                            getBitstreamSwitching() const;
                void                            addRepresentation( Representation *rep );
                virtual Url                     getUrlSegment() const; /* reimpl */

            private:
                bool                            subsegmentAlignmentFlag;
                std::vector<Representation *>   representations;
                const SegmentInfoDefault*       segmentInfoDefault;
                bool                            isBitstreamSwitching;
                SegmentTemplate *               mediaTemplate;
                SegmentTemplate *               initTemplate;
        };
    }
}

#endif /* ADAPTATIONSET_H_ */
