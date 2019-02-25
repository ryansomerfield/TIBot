;; Auto-generated. Do not edit!


(when (boundp 'cardriver::infrared)
  (if (not (find-package "CARDRIVER"))
    (make-package "CARDRIVER"))
  (shadow 'infrared (find-package "CARDRIVER")))
(unless (find-package "CARDRIVER::INFRARED")
  (make-package "CARDRIVER::INFRARED"))

(in-package "ROS")
;;//! \htmlinclude infrared.msg.html


(defclass cardriver::infrared
  :super ros::object
  :slots (_left _middle _right ))

(defmethod cardriver::infrared
  (:init
   (&key
    ((:left __left) 0)
    ((:middle __middle) 0)
    ((:right __right) 0)
    )
   (send-super :init)
   (setq _left (round __left))
   (setq _middle (round __middle))
   (setq _right (round __right))
   self)
  (:left
   (&optional __left)
   (if __left (setq _left __left)) _left)
  (:middle
   (&optional __middle)
   (if __middle (setq _middle __middle)) _middle)
  (:right
   (&optional __right)
   (if __right (setq _right __right)) _right)
  (:serialization-length
   ()
   (+
    ;; uint8 _left
    1
    ;; uint8 _middle
    1
    ;; uint8 _right
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _left
       (write-byte _left s)
     ;; uint8 _middle
       (write-byte _middle s)
     ;; uint8 _right
       (write-byte _right s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _left
     (setq _left (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _middle
     (setq _middle (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _right
     (setq _right (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get cardriver::infrared :md5sum-) "9ac8351df0827afe6affba478269ed96")
(setf (get cardriver::infrared :datatype-) "cardriver/infrared")
(setf (get cardriver::infrared :definition-)
      "uint8 left
uint8 middle
uint8 right

")



(provide :cardriver/infrared "9ac8351df0827afe6affba478269ed96")


