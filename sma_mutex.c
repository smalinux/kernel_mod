static DEFINE_MUTEX(write_lock);


if (mutex_lock_interruptible(&write_lock))
	return -ERESTARTSYS;


mutex_unlock(&write_lock);