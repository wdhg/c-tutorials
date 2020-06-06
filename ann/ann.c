#include "ann.h"

/* Creates and returns a new ann. */
ann_t *ann_create(int num_layers, int *layer_outputs) {
  /**** PART 2 - QUESTION 1 ****/
  ann_t *ann = (ann_t *)calloc(1, sizeof(ann_t));
  ann->input_layer = layer_init(layer_create(), layer_outputs[0], NULL);
  layer_t *prev_layer = ann->input_layer;
  for (int i = 1; i < num_layers; i++) {
    layer_t *layer = layer_init(layer_create(), layer_outputs[i], prev_layer);
  }
  ann->output_layer = prev_layer->next;
  return ann;
  /* 4 MARKS */
}

/* Frees the space allocated to ann. */
void ann_free(ann_t *ann) {
  /**** PART 2 - QUESTION 2 ****/
  layer_t *layer = ann->input_layer;
  while (layer != NULL) {
    layer_t *next = layer->next;
    layer_free(layer);
    layer = next;
  }
  /* 2 MARKS */
}

/* Forward run of given ann with inputs. */
void ann_predict(ann_t const *ann, double const *inputs) {
  /**** PART 2 - QUESTION 3 ****/
  ann->input_layer->outputs = inputs;
  layer_t layer = ann->input_layer->next;
  while (layer != NULL) {
    layer_compute_outputs(layer);
    layer = layer->next;
  }
  /* 2 MARKS */
}

/* Trains the ann with single backprop update. */
void ann_train(ann_t const *ann, double const *inputs, double const *targets,
               double l_rate) {
  /* Sanity checks. */
  assert(ann != NULL);
  assert(inputs != NULL);
  assert(targets != NULL);
  assert(l_rate > 0);

  /* Run forward pass. */
  ann_predict(ann, inputs);

  /**** PART 2 - QUESTION 4 ****/

  /* 3 MARKS */
}
