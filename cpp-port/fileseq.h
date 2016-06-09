#ifndef FILESEQ_FILESEQ_H_
#define FILESEQ_FILESEQ_H_

#include "frameset.h"
#include "sequence.h"
#include "types.h"

#include <vector>

namespace fileseq {

/*!
Takes a vector of frame numbers and
compresses them into a frame range string.

If sorted == true, pre-sort the frames instead of respecting
their current order in the range.

If zfill > 1, then pad out each number with "0" to the given
total width.
*/
std::string framesToFrameRange(const Frames &frames, bool sorted=false, int zfill=0);

/*!
isFrameRange returns true if the given string is a valid frame
range format. Any padding characters, such as '#' and '@' are ignored.
*/
bool isFrameRange(const std::string &frange);

/*!
FindSequenceOnDisk takes a string that is a compatible/parsible
FileSequence pattern, and finds a sequence on disk which matches
the basename and extension.
If no match is found, an invalid FileSequence is returned.
If an error occurs while reading the filesystem, it can be
captured by passing a fileseq::Status pointer.
*/
FileSequence findSequenceOnDisk(const std::string &pattern,
                                Status* ok=NULL);

/*!
FindSequenceOnDisk takes a string that is a compatible/parsible
FileSequence pattern, and finds a sequence on disk which matches
the basename and extension. The returned seq will use the given
padding style.
If no match is found, an invalid FileSequence is returned.
If an error occurs while reading the filesystem, it can be
captured by passing a fileseq::Status pointer.
*/
FileSequence findSequenceOnDisk(const std::string &pattern,
                                PadStyle style=PadStyleDefault,
                                Status* ok=NULL);

/*!
FindSequencesOnDisk searches a given directory path and sorts all
valid sequence-compatible files into a list of FileSequence matches.
By default, only non-hidden sequences of files will be returned.
Extra options may be given to control whether things like hidden
files, or single (non-sequence) files should be included in the
search results.
*/
Status findSequencesOnDisk(FileSequences &seqs,
                           const std::string &path,
                           bool hiddenFiles=false,
                           bool singleFiles=false,
                           PadStyle style=PadStyleDefault);

} // fileseq

#endif // FILESEQ_FILESEQ_H_
