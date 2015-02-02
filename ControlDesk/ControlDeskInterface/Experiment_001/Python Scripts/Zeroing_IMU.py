#------------------------------------------------------------------------------
# Import modules
#------------------------------------------------------------------------------
import rtplib2               # base module for the demo
import os, sys


#--------------------------------------------------------------------------
# Set the name of the real-time hardware platform and the path of the demo
# application's variable description file.
#--------------------------------------------------------------------------
PlatformName = "ds1401"     # platform name as registered with ControlDesk or AutomationDesk
AppPath      = r"C:\Users\Sebastian\Documents\GitHub\MA_Active_Steering_Dolly\ControlDesk\ControlDeskInterface\Variable Descriptions\can_new.sdf\can_new.sdf"


def zeroing ():
    
    #--------------------------------------------------------------------------
    # Enclose rtplib2 class objects with try:-finally: block, to ensure that
    # these objects will be deleted at the end of the function.
    #--------------------------------------------------------------------------
    try:
        # Start  
        print "Starting zeroing" 
      
        #----------------------------------------------------------------------
        # Create an Appl class object
        #----------------------------------------------------------------------
        myAppl = rtplib2.Appl(AppPath, PlatformName) 

        #----------------------------------------------------------------------
        # Create Variable class objects
        #Accelerometer------------------------------------------------------------------
        x_accel_raw_str = 'Platform()://Model Root/Arduino/accel_zeroing/<x>'
        y_accel_raw_str = 'Platform()://Model Root/Arduino/accel_zeroing/<y>'
        z_accel_raw_str = 'Platform()://Model Root/Arduino/accel_zeroing/<z>'
        x_accel_init_str       = 'Platform()://Model Root/Arduino/accel_zeroing/Accelerometer_init_x/Value'
        y_accel_init_str       = 'Platform()://Model Root/Arduino/accel_zeroing/Accelerometer_init_y/Value'
        z_accel_init_str       = 'Platform()://Model Root/Arduino/accel_zeroing/Accelerometer_init_z\n/Value'
        

        x_accel_raw     = myAppl.Variable(x_accel_raw_str)
        y_accel_raw     = myAppl.Variable(y_accel_raw_str)
        z_accel_raw     = myAppl.Variable(z_accel_raw_str)
        x_accel_init           = myAppl.Variable(x_accel_init_str)
        y_accel_init           = myAppl.Variable(y_accel_init_str)
        z_accel_init           = myAppl.Variable(z_accel_init_str)
        x_accel_raw_value  = x_accel_raw.Read()
        y_accel_raw_value  = y_accel_raw.Read()
        z_accel_raw_value  = z_accel_raw.Read()
        # Read values before changing
        x_accel_init_value_before = x_accel_init.Read()
        y_accel_init_value_before = y_accel_init.Read()
        z_accel_init_value_before = z_accel_init.Read()        
        print "\nx_accel_init before change: %f" % x_accel_init_value_before
        print "\ny_accel_init before change: %f" % y_accel_init_value_before
        print "\nz_accel_init before change: %f" % z_accel_init_value_before
        # Set accel init 
        x_accel_init.Write(-x_accel_raw_value)
        y_accel_init.Write(-y_accel_raw_value)
        z_accel_init.Write(-z_accel_raw_value)

        # Read accel init after changing
        x_accel_init_after = x_accel_init.Read()
        y_accel_init_after = y_accel_init.Read()
        z_accel_init_after = z_accel_init.Read()
        print "x_accel_init after change:  %f" % x_accel_init_after
        print "y_accel_init after change:  %f" % y_accel_init_after
        print "z_accel_init after change:  %f" % z_accel_init_after


        #Angle-----------------------------------------------------------
        x_angle_raw_str = 'Platform()://Model Root/Arduino/angle_zeroing/<x>'
        y_angle_raw_str = 'Platform()://Model Root/Arduino/angle_zeroing/<y>'
        z_angle_raw_str = 'Platform()://Model Root/Arduino/angle_zeroing/<z>'
        x_angle_init_str       = 'Platform()://Model Root/Arduino/angle_zeroing/angle_init_x/Value'
        y_angle_init_str       = 'Platform()://Model Root/Arduino/angle_zeroing/angle_init_y/Value'
        z_angle_init_str       = 'Platform()://Model Root/Arduino/angle_zeroing/angle_init_z\n/Value'
        
        x_angle_raw     = myAppl.Variable(x_angle_raw_str)
        y_angle_raw     = myAppl.Variable(y_angle_raw_str)
        z_angle_raw     = myAppl.Variable(z_angle_raw_str)
        x_angle_init           = myAppl.Variable(x_angle_init_str)
        y_angle_init           = myAppl.Variable(y_angle_init_str)
        z_angle_init           = myAppl.Variable(z_angle_init_str) 
        
        
        x_angle_raw_value  = x_angle_raw.Read()
        y_angle_raw_value  = y_angle_raw.Read()
        z_angle_raw_value  = z_angle_raw.Read()                 
        
        
        x_angle_init_value_before = x_angle_init.Read()
        y_angle_init_value_before = y_angle_init.Read()
        z_angle_init_value_before = z_angle_init.Read()
        print "\nx_angle_init before change: %f" % x_angle_init_value_before
        print "\ny_angle_init before change: %f" % y_angle_init_value_before
        print "\nz_angle_init before change: %f" % z_angle_init_value_before
        # Set angle init 
        x_angle_init.Write(-x_angle_raw_value)
        y_angle_init.Write(-y_angle_raw_value)
        z_angle_init.Write(-z_angle_raw_value)

        # Read accel init after changing
        x_angle_init_after = x_angle_init.Read()
        y_angle_init_after = y_angle_init.Read()
        z_angle_init_after = z_angle_init.Read()
        print "x_angle_init after change:  %f" % x_angle_init_after
        print "y_angle_init after change:  %f" % y_angle_init_after
        print "z_angle_init after change:  %f" % z_angle_init_after
        
        #Gyro-----------------------------------------------------------
        x_gyro_raw_str = 'Platform()://Model Root/Arduino/gyro_zeroing/<x>'
        y_gyro_raw_str = 'Platform()://Model Root/Arduino/gyro_zeroing/<y>'
        z_gyro_raw_str = 'Platform()://Model Root/Arduino/gyro_zeroing/<z>'
        x_gyro_init_str       =  'Platform()://Model Root/Arduino/gyro_zeroing/gyro_init_x/Value'
        y_gyro_init_str       =  'Platform()://Model Root/Arduino/gyro_zeroing/gyro_init_y/Value'
        z_gyro_init_str       =  'Platform()://Model Root/Arduino/gyro_zeroing/gyro_init_z\n/Value'
        
        x_gyro_raw     = myAppl.Variable(x_gyro_raw_str)
        y_gyro_raw     = myAppl.Variable(y_gyro_raw_str)
        z_gyro_raw     = myAppl.Variable(z_gyro_raw_str)
        x_gyro_init           = myAppl.Variable(x_gyro_init_str)
        y_gyro_init           = myAppl.Variable(y_gyro_init_str)
        z_gyro_init           = myAppl.Variable(z_gyro_init_str) 
        
        
        x_gyro_raw_value  = x_gyro_raw.Read()
        y_gyro_raw_value  = y_gyro_raw.Read()
        z_gyro_raw_value  = z_gyro_raw.Read()                 
        
        
        x_gyro_init_value_before = x_gyro_init.Read()
        y_gyro_init_value_before = y_gyro_init.Read()
        z_gyro_init_value_before = z_gyro_init.Read()
        print "\nx_gyro_init before change: %f" % x_gyro_init_value_before
        print "\ny_gyro_init before change: %f" % y_gyro_init_value_before
        print "\nz_gyro_init before change: %f" % z_gyro_init_value_before
        # Set gyro init 
        x_gyro_init.Write(-x_gyro_raw_value)
        y_gyro_init.Write(-y_gyro_raw_value)
        z_gyro_init.Write(-z_gyro_raw_value)

        # Read gyro init after changing
        x_gyro_init_after = x_gyro_init.Read()
        y_gyro_init_after = y_gyro_init.Read()
        z_gyro_init_after = z_gyro_init.Read()
        print "x_gyro_init after change:  %f" % x_gyro_init_after
        print "y_gyro_init after change:  %f" % y_gyro_init_after
        print "z_gyro_init after change:  %f" % z_gyro_init_after

        
        # Demo finished
        print "\n... zeroing finished."   
    finally:
        #----------------------------------------------------------------------
        # Delete all rtplib2 objects
        #----------------------------------------------------------------------
        x_accel_raw = None
        y_accel_raw = None  
        z_accel_raw = None
        x_accel_init       = None
        y_accel_init       = None
        z_accel_init       = None
        x_angle_raw = None
        y_angle_raw = None  
        z_angle_raw = None
        x_angle_init       = None
        y_angle_init       = None
        z_angle_init       = None
        x_gyro_raw = None
        y_gyro_raw = None  
        z_gyro_raw = None
        x_gyro_init       = None
        y_gyro_init       = None
        z_gyro_init       = None

        myAppl       = None
zeroing()
