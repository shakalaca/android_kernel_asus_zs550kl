#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/fs.h>
#include <linux/init.h>

static struct proc_dir_entry *project_id_proc_file;
static int project_id_proc_read(struct seq_file *buf, void *v)
{
	seq_printf(buf, "%d\n", asus_project_id);
	return 0;
}

static int project_id_proc_open(struct inode *inode, struct  file *file)
{
    return single_open(file, project_id_proc_read, NULL);
}


static struct file_operations project_id_proc_ops = {
	.open = project_id_proc_open,
	.read = seq_read,
	.release = single_release,
};

static void create_project_id_proc_file(void)
{
    project_id_proc_file = proc_create("apid", 0444,NULL, &project_id_proc_ops);
    if(!project_id_proc_file){
	printk("create project_id_proc_file failed!\n");
    }
}


static struct proc_dir_entry *project_hw_proc_file;
static int project_hw_proc_read(struct seq_file *buf, void *v)
{
	seq_printf(buf, "%d\n", asus_hw_id);
	return 0;
}

static int project_hw_proc_open(struct inode *inode, struct  file *file)
{
    return single_open(file, project_hw_proc_read, NULL);
}


static struct file_operations project_hw_proc_ops = {
	.open = project_hw_proc_open,
	.read = seq_read,
	.release = single_release,
};

static void create_project_hw_proc_file(void)
{
    project_hw_proc_file = proc_create("apsta", 0444,NULL, &project_hw_proc_ops);
    if(!project_hw_proc_file){
	printk("create project_stage_proc_file failed!\n");
    }
}

//<ASUS-Jessie_Tian-20160617>create node rf_id+++
static struct proc_dir_entry *project_rf_proc_file;
static int project_rf_proc_read(struct seq_file *buf, void *v)
{
	seq_printf(buf, "%d\n", asus_rf_id);
	return 0;
}

static int project_rf_proc_open(struct inode *inode, struct  file *file)
{
    return single_open(file, project_rf_proc_read, NULL);
}


static struct file_operations project_rf_proc_ops = {
	.open = project_rf_proc_open,
	.read = seq_read,
	.release = single_release,
};

static void create_project_rf_proc_file(void)
{
    project_rf_proc_file = proc_create("aprf", 0444,NULL, &project_rf_proc_ops);
    if(!project_rf_proc_file){
	printk("create project_rf_proc_file failed!\n");
    }
}
//<ASUS-Jessie_Tian-20160617>create node rf_id---

static int __init proc_asusPRJ_init(void)
{
	create_project_id_proc_file();
	create_project_hw_proc_file();
	create_project_rf_proc_file();
	return 0;
}
module_init(proc_asusPRJ_init);
