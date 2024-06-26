/*===========================================================================
*
*                            PUBLIC DOMAIN NOTICE
*               National Center for Biotechnology Information
*
*  This software/database is a "United States Government Work" under the
*  terms of the United States Copyright Act.  It was written as part of
*  the author's official duties as a United States Government employee and
*  thus cannot be copyrighted.  This software/database is freely available
*  to the public for use. The National Library of Medicine and the U.S.
*  Government have not placed any restriction on its use or reproduction.
*
*  Although all reasonable efforts have been taken to ensure the accuracy
*  and reliability of the software and data, the NLM and the U.S.
*  Government do not and cannot warrant the performance or results that
*  may be obtained by using this software or data. The NLM and the U.S.
*  Government disclaim all warranties, express or implied, including
*  warranties of performance, merchantability or fitness for any particular
*  purpose.
*
*  Please cite the author in any work or product based on this material.
*
* ===========================================================================
*
*/

#ifndef _h_file_tools_
#define _h_file_tools_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _h_klib_rc_
#include <klib/rc.h>
#endif

#ifndef _h_kfs_directory_
#include <kfs/directory.h>
#endif

#ifndef _h_kfs_file_
#include <kfs/file.h>
#endif

#ifndef _h_klib_namelist_
#include <klib/namelist.h>
#endif

rc_t ft_create_this_dir( KDirectory * dir, const String * dir_name, bool force );
rc_t ft_create_this_dir_2( KDirectory * dir, const char * dir_name, bool force );

bool ft_file_exists( const KDirectory * dir, const char * fmt, ... );
bool ft_dir_exists( const KDirectory * dir, const char * fmt, ... );

rc_t ft_delete_files( KDirectory * dir, const VNamelist * files, bool details );
rc_t ft_delete_dirs( KDirectory * dir, const VNamelist * dirs, bool details );

uint64_t ft_file_size( const KDirectory * dir, const char * fmt, ... );
uint64_t ft_total_size_of_files_in_list( KDirectory * dir, const VNamelist * files );

rc_t ft_make_buffered_for_read( KDirectory * dir, const struct KFile ** f,
                                const char * filename, size_t buf_size );

rc_t ft_release_file( const struct KFile * f, const char * err_msg, ... );
rc_t ft_wrap_file_in_buffer( struct KFile ** f, size_t buffer_size, const char * err_msg );

rc_t ft_available_space_disk_space( const KDirectory * dir, const char * path, size_t * res, bool is_file );

#ifdef __cplusplus
}
#endif

#endif
