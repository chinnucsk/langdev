(ns bres
  (:import (javax.swing JFrame JPanel)
           (java.awt Canvas)))

(defn go [x y]
  (let [frame (JFrame.)]
    (.. frame getContentPane (add (Canvas.)))
    (doto frame
      (.setTitle (str "Bresenham with Clojure"))
      (.setDefaultCloseOperation JFrame/DISPOSE_ON_CLOSE)
      (.setSize x y)
      (.setVisible true))))
