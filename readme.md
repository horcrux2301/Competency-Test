# Competency Test Repository.

### Implementation of a Generic Segment Tree.

`class Segment Tree` has

1. 4 private data members `HeadNode`, `startIndex`, `endIndex` and  and `ComparisonFunction`.
2. 4 private functions `CreateTree`, `PrintTree`, `ComputeValue` and `UpdateValue` .
3. 4 public functions `InitSegmentTree`, `PrintSegmentTree`, `PrintComputedValue`, `UpdateSegmentTree`  that are used to communicate with private functions and data members.

`ComparisonFunction` is used as a lambda on the basis of which merging at the nodes takes place.

I have included two subdirectories `Range Minimum Query` and `Range Sum` to check for the accuracy of the code.
