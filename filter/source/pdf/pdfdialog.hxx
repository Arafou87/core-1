/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_FILTER_SOURCE_PDF_PDFDIALOG_HXX
#define INCLUDED_FILTER_SOURCE_PDF_PDFDIALOG_HXX

#include "pdffilter.hxx"
#include <svtools/genericunodialog.hxx>

#include <comphelper/proparrhlp.hxx>
#include <cppuhelper/implbase.hxx>


namespace vcl { class Window; }

typedef ::cppu::ImplInheritanceHelper < ::svt::OGenericUnoDialog, XPropertyAccess, XExporter >  PDFDialog_Base;

class PDFDialog final:
    public PDFDialog_Base,
    public ::comphelper::OPropertyArrayUsageHelper< PDFDialog >
{
private:
    Sequence< PropertyValue >   maMediaDescriptor;
    Sequence< PropertyValue >   maFilterData;
    Reference< XComponent >     mxSrcDoc;

    // OGenericUnoDialog
    virtual Sequence< sal_Int8 > SAL_CALL getImplementationId() override;
    virtual OUString SAL_CALL getImplementationName() override;
    virtual Sequence< OUString > SAL_CALL getSupportedServiceNames() override;
    virtual svt::OGenericUnoDialog::Dialog createDialog(const css::uno::Reference<css::awt::XWindow>& rParent) override;
    virtual void executedDialog( sal_Int16 nExecutionResult ) override;
    virtual Reference< XPropertySetInfo>  SAL_CALL getPropertySetInfo() override;
    virtual ::cppu::IPropertyArrayHelper& SAL_CALL getInfoHelper() override;
    virtual ::cppu::IPropertyArrayHelper* createArrayHelper( ) const override;

    // XPropertyAccess
    using OPropertySetHelper::getPropertyValues;
    virtual Sequence< PropertyValue > SAL_CALL getPropertyValues(  ) override;
    using OPropertySetHelper::setPropertyValues;
    virtual void SAL_CALL setPropertyValues( const Sequence< PropertyValue >& aProps ) override;

    // XExporter
    virtual void SAL_CALL setSourceDocument( const Reference< XComponent >& xDoc ) override;

public:

    explicit    PDFDialog( const Reference< XComponentContext >& rxContext );
    virtual     ~PDFDialog() override;
};

/// @throws RuntimeException
OUString PDFDialog_getImplementationName ();
/// @throws RuntimeException
Sequence< OUString > PDFDialog_getSupportedServiceNames();
/// @throws Exception
Reference< XInterface > PDFDialog_createInstance( const Reference< XMultiServiceFactory > & rSMgr);

#endif // INCLUDED_FILTER_SOURCE_PDF_PDFDIALOG_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
