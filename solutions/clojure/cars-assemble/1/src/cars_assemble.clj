(ns cars-assemble)

(defn production-rate
  "Returns the assembly line's production rate per hour,
   taking into account its success rate"
  [speed]
  (cond
    (== speed 0) (* speed 221)
    (<= 1 speed 4) (* (* speed 221) 1.0)
    (<= 5 speed 8) (* (* speed 221) 0.9)
    (== speed 9) (* (* speed 221) 0.8)
    (== speed 10) (* (* speed 221) 0.77)
    :else ("Invalid Speed!")
    )
  )

(defn working-items
  "Calculates how many working cars are produced per minute"
  [speed]
    (cond
    (== speed 0) (* speed 221)
    (<= 1 speed 4) (int (/ (* (* speed 221) 1.0) 60))
    (<= 5 speed 8) (int (/ (* (* speed 221) 0.9) 60))
    (== speed 9) (int (/ (* (* speed 221) 0.8) 60))
    (== speed 10) (int (/ (* (* speed 221) 0.77) 60))
    :else ("Invalid Speed!")
    )
  )
