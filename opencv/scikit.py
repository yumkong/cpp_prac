# load data
import numpy as np
import urllib
#dataset url
url = "http://archive.ics.uci.edu/ml/machine-learning-databases/pima-indians-diabetes/pima-indians-diabetes.data"
#download file
raw_data = urllib.urlopen(url)
# load the CSV file as a numpy matrix
dataset = np.loadtxt(raw_data, delimiter = ",")
#separate the data from the target attributes
X = dataset[:, 0:7]
y = dataset[:, 8]

# most ml algo's gradient are sensitive to data's scale, so normalize before using

from sklearn import preprocessing
#normalize the data attributes
normalized_X = preprocessing.normalize(X)
#standardize the data attributes
standardized_x = preprocessing.scale(X)

# when deal with practical problem, feature engineering is a creative process, more dependent on intuitive and speciality
# use Tree Algorithms to compute feature's information
from sklearn import metrics
from sklearn.ensemble import ExtraTreesClassifier
model = ExtraTreesClassifier()
model.fit(X, y)
# display the relative importance of each attribute
print(model.feature_importances_)

#logistic regression: Advantage: given the prob of data's category
from sklearn import metrics
from sklearn.linear_model import LogisticRegression
model = LogisticRegression()
model.fit(X, y)
print model
# make prediction
expected = y
predicted = model.predict(X)
# summarize the fit of the model (the prediction performance)
print(metrics.classification_report(expected, predicted))
print(metrics.confusion_matrix(expected, predicted))

#### https://zhuanlan.zhihu.com/p/25723719
###https://zhuanlan.zhihu.com/p/24770526
