(defn s [x y z]
  (fn [x]
    (fn [y]
      (fn [z]
        ((x z) (y z))))))
