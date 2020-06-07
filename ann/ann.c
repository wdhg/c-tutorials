#include "ann.h"

#include <stdio.h>
#include <string.h>

/* Creates and returns a new ann. */
ann_t *ann_create(int num_layers, int *layer_outputs) {
  /**** PART 2 - QUESTION 1 ****/
  ann_t *ann = (ann_t *)calloc(1, sizeof(ann_t));
  layer_t *prev_layer = NULL;
  for (int i = 0; i < num_layers; i++) {
    layer_t *layer = layer_create();
    bool err = layer_init(layer, layer_outputs[i], prev_layer);
    if (err) {
      return NULL;
    }
    if (i == 0) {
      ann->input_layer = layer;
    }
    prev_layer = layer;
  }
  ann->output_layer = prev_layer;
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
  free(ann);
  /* 2 MARKS */
}

/* Forward run of given ann with inputs. */
void ann_predict(ann_t const *ann, double const *inputs) {
  /**** PART 2 - QUESTION 3 ****/
  for (int input = 0; input < ann->input_layer->num_outputs; input++) {
    ann->input_layer->outputs[input] = inputs[input];
  }
  layer_t *layer = ann->input_layer->next;
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
  for (int output = 0; output < ann->output_layer->num_outputs; output++) {
    double output_value = ann->output_layer->outputs[output];
    double difference = targets[output] - output_value;
    ann->output_layer->deltas[output] = sigmoidprime(output_value) * difference;
  }
  layer_update(ann->output_layer, l_rate);
  layer_t *layer = ann->output_layer->prev;
  while (layer->prev != NULL) {
    layer_compute_deltas(layer);
    layer_update(layer, l_rate);
    layer = layer->prev;
  }
  /* 3 MARKS */
}
