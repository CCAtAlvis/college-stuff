from flask import Blueprint, request, jsonify
import pickle

file = 'iris.model'
model = pickle.load(open(file, 'rb'))

model_predictor = Blueprint('model_predictor', __name__)

@model_predictor.route('/predict', methods=['POST'])
def predict_value():
    sepal_l = request.get_json()['sepal_l']
    sepal_w = request.get_json()['sepal_w']
    petal_l = request.get_json()['petal_l']
    petal_w = request.get_json()['petal_w']

    p = model.predict([
        [sepal_l, sepal_w, petal_l, petal_w]
    ])
    flowers = ['setosa', 'versicolor', 'virginica', 'the system crashed']

    # print(p)
    return jsonify({
        'flower': flowers[p[0]]
    })

