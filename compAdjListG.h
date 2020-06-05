#ifndef ADJLISTGAPS
#define ADJLISTGAPS

#include "integerEncoding.h"

typedef struct _compadjlistG{
	uint64_t n; // number of nodes
	uint64_t e; // number of edges
  
  uint64_t *cd; // n's neighbours are in [ cd[n] .. cd[n+1] [
  uint8_t *adj;
  uint64_t nbb; //nb bytes used by adj

}CompAdjListG;

CompAdjListG *make_CompAdjListG();

void free_CompAdjListG(CompAdjListG *alg);

CompAdjListG *load_CompAdjListG(char *path, uint8_t ign, 
  uint8_t *encoding_function(uint8_t *arr, uint64_t *u, uint64_t val), 
  uint64_t expl_function(uint64_t val), uint64_t *u);

void print_CompAdjListG(CompAdjListG *alg, 
  uint64_t decoding_function(uint8_t *arr,uint64_t *s));

void write_CompAdjListG(CompAdjListG *alg, uint8_t id, char *path);

CompAdjListG *read_CompAdjListG(char *path, uint8_t *id);

uint64_t *bfs_CompAdjListG(
  CompAdjListG *alg,uint64_t curr,
  uint8_t *seen,uint64_t *nbvals,
  uint64_t decoding_function(uint8_t *arr,uint64_t *s));

#endif 