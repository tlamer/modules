static ssize_t procfile_read(struct file *filp,
		char *buffer,
		size_t length,
		loff_t *offset);
static int procfile_open(struct inode *, struct file *);
static int procfile_release(struct inode *, struct file *);
